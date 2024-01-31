#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N_MAX 10  // Maximum size for analysis

// Function declarations
void bruteForceAssignment(int costMatrix[][N_MAX], int n);
void swap(int *a, int *b);
void reverse(int arr[], int start, int end);
int next_permutation(int arr[], int n);
void printArray(int arr[], int n);
void printAssignment(int assignment[], int n);
int calculateCost(int costMatrix[][N_MAX], int assignment[], int n);
void generateRandomCostMatrix(int costMatrix[][N_MAX], int n);

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(int arr[], int start, int end) {
    while (start < end) {
        swap(&arr[start], &arr[end]);
        start++;
        end--;
    }
}

int next_permutation(int arr[], int n) {
    int i = n - 2;
    while (i >= 0 && arr[i] >= arr[i + 1]) {
        i--;
    }

    if (i < 0) {
        return 0;  // No more permutations
    }

    int j = n - 1;
    while (arr[j] <= arr[i]) {
        j--;
    }

    swap(&arr[i], &arr[j]);
    reverse(arr, i + 1, n - 1);

    return 1;  // Next permutation generated
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void printAssignment(int assignment[], int n) {
    printf("Assignment: ");
    for (int i = 0; i < n; i++) {
        printf("(%d, %d) ", i + 1, assignment[i] + 1);
    }
    printf("\n");
}

int calculateCost(int costMatrix[][N_MAX], int assignment[], int n) {
    int totalCost = 0;
    for (int i = 0; i < n; i++) {
        totalCost += costMatrix[i][assignment[i]];
    }
    return totalCost;
}

void generateRandomCostMatrix(int costMatrix[][N_MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            costMatrix[i][j] = rand() % 10 + 1;  // Random cost between 1 and 10
        }
    }
}

void bruteForceAssignment(int costMatrix[][N_MAX], int n) {
    int assignment[N_MAX];
    for (int i = 0; i < n; i++) {
        assignment[i] = i;  // Initial assignment as identity permutation
    }

    int minCost = calculateCost(costMatrix, assignment, n);
    int tempAssignment[N_MAX];

    do {
        int currentCost = calculateCost(costMatrix, assignment, n);
        if (currentCost < minCost) {
            minCost = currentCost;
            for (int i = 0; i < n; i++) {
                tempAssignment[i] = assignment[i];
            }
        }
    } while (next_permutation(assignment, n));

    printf("Minimum Cost: %d\n", minCost);
    printAssignment(tempAssignment, n);
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    printf("Size\tTime (ms)\n");

    for (int n = 2; n <= N_MAX; n++) {
        int costMatrix[N_MAX][N_MAX];

        // Generate random cost matrix
        generateRandomCostMatrix(costMatrix, n);

        clock_t start_time = clock();
        bruteForceAssignment(costMatrix, n);
        clock_t end_time = clock();

        double elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC * 1000.0;

        printf("%d\t%.2f\n", n, elapsed_time);
    }

    return 0;
}
