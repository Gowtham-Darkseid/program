#include <stdio.h>

int quicksort(int qu[], int lw, int hi);
int quick[10], n, i, j, max, min, pivot, temp;

void main() {
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the values: ");
    
    for(i = 0; i < n; i++) {
        scanf("%d", &quick[i]);
    }

    min = 0;
    max = n - 1;

    // Call quicksort function
    quicksort(quick, min, max);

    // Output sorted elements
    printf("\nSorted elements are:\n");
    for(i = 0; i < n; i++) {
        printf("%d\t", quick[i]);
    }

    getch(); // Optional, for pausing before exit
}

int quicksort(int qu[], int lw, int hi) {
    int i, j, pivot;

    if(lw < hi) {
        pivot = lw;    // Choosing the first element as pivot
        i = lw;
        j = hi;

        while(i < j) {
            // Increment i while elements are less than pivot
            while(qu[i] <= qu[pivot] && i <= hi) i++;

            // Decrement j while elements are greater than pivot
            while(qu[j] > qu[pivot] && j >= lw) j--;

            // If i is smaller than j, swap
            if(i < j) {
                temp = qu[i];
                qu[i] = qu[j];
                qu[j] = temp;
            }
        }

        // Swap pivot with qu[j] to partition the array
        temp = qu[j];
        qu[j] = qu[pivot];
        qu[pivot] = temp;

        // Print the array after each partition
        printf("Partitioned array: ");
        for(i = 0; i < n; i++) {
            printf("%d\t", qu[i]);
        }
        printf("\n");

        // Recursively sort the subarrays
        quicksort(qu, lw, j - 1);    // Left subarray
        quicksort(qu, j + 1, hi);    // Right subarray
    }

    return 0;
}
