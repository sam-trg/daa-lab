#include <stdio.h>

void heapify(int h[], int n) {
    int i, k, v, j;
    for (i = n / 2 - 1; i >= 0; i--) {
        k = i;
        v = h[k];
        int heapify = 0;
        while (heapify == 0 && 2 * k <= n) {
            j = 2 * k;
            if (j < n && h[j] < h[j + 1]) {
                j = j + 1;
            }
            if (v >= h[j]) {
                heapify = 1;
            } else {
                h[k] = h[j];
                k = j;
            }
        }
        h[k] = v;
    }
}

int main() {
    int h[20], i, n;

    printf("\nEnter the number of Elements: ");
    scanf("%d", &n);

    printf("\nEnter the Elements: ");
    for (i = 1; i <= n; i++) {
        scanf("%d", &h[i]);
    }

    printf("\nDisplay the array: ");
    for (i = 1; i <= n; i++) {
        printf("%d\t", h[i]);
    }

    heapify(h, n);

    printf("\nThe heap created: ");
    for (i = 1; i <= n; i++) {
        printf("%d\t", h[i]);
    }

    return 0;
}
