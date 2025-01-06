#include <stdio.h>

void mergesort(int a[], int i, int j);
void merge(int a[], int i1, int j1, int i2, int j2);

int main() {
    int a[30], n, i;

    // Input: Number of elements
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Input: Array elements
    printf("Enter array elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Call Merge Sort
    mergesort(a, 0, n - 1);

    // Output: Sorted array
    printf("\nSorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}

// Merge Sort function
void mergesort(int a[], int i, int j) {
    int mid;

    if (i < j) {
        mid = (i + j) / 2;

        // Recursive calls for left and right subarrays
        mergesort(a, i, mid);
        mergesort(a, mid + 1, j);

        // Merge the sorted subarrays
        merge(a, i, mid, mid + 1, j);
    }
}

// Merge function
void merge(int a[], int i1, int j1, int i2, int j2) {
    int temp[50];
    int i = i1, j = i2, k = 0;

    // Merge the two subarrays into temp[]
    while (i <= j1 && j <= j2) {
        if (a[i] < a[j]) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
        }
    }

    // Copy remaining elements of the first subarray, if any
    while (i <= j1) {
        temp[k++] = a[i++];
    }

    // Copy remaining elements of the second subarray, if any
    while (j <= j2) {
        temp[k++] = a[j++];
    }

    // Copy sorted elements back into the original array
    for (i = i1, j = 0; i <= j2; i++, j++) {
        a[i] = temp[j];
    }
}
