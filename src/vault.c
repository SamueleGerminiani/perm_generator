/* Vault code: you do not need to read or modify this file :)
 *
 * The fragment is encrypted: it can only be decrypted with a key computed
 * from the correct permutations.
 */
#include <stdio.h>
#include <vault.h>

#define FNV_START 2166136261u

static unsigned int count = 0;
static unsigned int sum = 0;

static unsigned int mix(unsigned int h, unsigned int v) {
    for (int i = 0; i < 4; i++) {
        h ^= (v >> (8 * i)) & 0xff;
        h *= 16777619u;
    }
    return h;
}

static unsigned int nextByte(unsigned int *s) {
    *s ^= *s << 13;
    *s ^= *s >> 17;
    *s ^= *s << 5;
    return *s & 0xff;
}

void vaultFeed(const int list[], int len) {
    unsigned int value = 0;
    for (int i = 0; i < len; i++) {
        value = value * len + list[i];
    }
    count++;
    sum += value;
}

void vaultReveal(int n) {
    static const unsigned char enc[] = {0x17, 0x17, 0x42, 0x5f, 0x25};
    const int len = sizeof(enc);
    char fragment[sizeof(enc) + 1];

    unsigned int s = mix(mix(mix(FNV_START, n), count), sum);
    unsigned int h = FNV_START;
    for (int i = 0; i < len; i++) {
        fragment[i] = enc[i] ^ nextByte(&s);
        h = mix(h, (unsigned char)fragment[i]);
    }
    fragment[len] = '\0';

    if (h == 0x3cc6a11fu) {
        printf("\n*** Vault fragment #1 of 4: \"%s\" ***\n", fragment);
    }
}
