![image](https://github.com/sam-trg/daa-lab/assets/90459209/96b7cad2-6757-49ab-8a45-0458158bfb8c)


[Right Click to open Data in New Tab](https://learnermanipal-my.sharepoint.com/:x:/r/personal/samarth_mitblr2022_learner_manipal_edu/Documents/DAA-LAB.xlsx?d=w5297308de2a242258f09dad285d6c59e&csf=1&web=1&e=nJeXPE&nav=MTVfezdGMzA0QTVELUI4RjgtNDRBMi05QzcyLURDQUM5MzJFQjJEM30)

# Selection Sort
```c
void selectionSort(int *a, unsigned int n) {
    unsigned int i, j, min;
    int temp;
    int opcount = 0; // introduce opcount
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            ++opcount; // increment opcount for every comparison
            if (a[j] < a[min])
                min = j;
        }
        // swap A[i] and A[min]
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
    printf("\nOperation Count %d\n", opcount);
}
```

# Bubble Sort
```c
void bubbleSort(int *a, unsigned int n) {
    unsigned int i, j;
    int temp;
    int opcount = 0; // introduce opcount
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            ++opcount; // increment opcount for every comparison
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    printf("Operation Count %d\n", opcount);
}
```
