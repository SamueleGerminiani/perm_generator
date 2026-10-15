/** @file vault.h
 *
 * Vault code: you do not need to read or modify this file :)
 */

/** Function to register a permutation found by the generator
 */
void vaultFeed(const int list[], int len);

/** Function to reveal the vault fragment (only if all permutations are correct)
 */
void vaultReveal(int n);
