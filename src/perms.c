#include <stdio.h>
#include <swap.h>
#include <perms.h>

// Function to generate permutations of an input list
void generatePermutations(int list[], int start, int end) {
    if (start == end) {

        // A permutation is found, print it
        for (unsigned int i = end; i >= 0; i--) {
            printf("%d ", list[i]);
            fflush(stdout);
        }
        printf("\n");
    } else {
        for (int i = start; i <= end; i++) {
            // Swap the current element with itself and all the following elements
            swap(&list[start], &list[i]);

            // Recursively generate permutations for the remaining elements
            generatePermutations(list, start + 1, end);

            // Restore the original order (backtracking)
            swap(&list[start], &list[i]);
        }
    }
}

