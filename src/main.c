/**
 * @file main.cc
 *
 * @brief Permutation generator
 *
 * @author Samuele Germiniani
 *
 */

#include <perms.h>
#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);

    int list[n];
    for (int i = 0; i < n; i++) {
        list[i]=i;
    }

    printf("Permutations:\n");
    generatePermutations(list, 0, n-1);

    return 0;
}
