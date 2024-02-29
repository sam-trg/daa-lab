#include <stdio.h>
#include <time.h>

void counting_sort(int A[], int n) {
    int i, j;
    int S[n];  // Use n for the size of S to avoid potential overflows
    int C[n + 1]; // Use n + 1 for the size of C to accommodate the range of elements

    // Initialize C to 0
    for (i = 0; i <= n; i++) {
        C[i] = 0;
    }

    // Count occurrences of each element
    for (i = 0; i < n; i++) {
        C[A[i]]++;
    }

    // Calculate cumulative frequencies (prefix sum)
    for (i = 1; i <= n; i++) {
        C[i] += C[i - 1];
    }

    // Place elements in sorted output array S
    for (i = n - 1; i >= 0; i--) {
        S[C[A[i]] - 1] = A[i];
        C[A[i]]--;
    }

    // Copy sorted elements back to A
    for (i = 0; i < n; i++) {
        A[i] = S[i];
    }
}

int main() {
    int n, i;
    clock_t start, end;
    double cpu_time_used;

    printf("Enter the number of integers: ");
    scanf("%d", &n);

    int A[n];
    printf("Enter the integers to be sorted:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    start = clock();

    counting_sort(A, n);

    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("\nThe sorted array is: ");
    for (i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }

    printf("\nTime taken for sorting: %f seconds\n", cpu_time_used);

    return 0;
}
