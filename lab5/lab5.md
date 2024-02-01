![image](https://github.com/sam-trg/daa-lab/assets/90459209/73278e6e-a60f-44d6-b073-2e20a8e7da3b)
![image](https://github.com/sam-trg/daa-lab/assets/90459209/e4643399-53d4-44ea-833f-7ba09ef7e072)

[Right Click to open Data in New Tab](https://learnermanipal-my.sharepoint.com/:x:/r/personal/samarth_mitblr2022_learner_manipal_edu/Documents/DAA-LAB.xlsx?d=w5297308de2a242258f09dad285d6c59e&csf=1&web=1&e=Vsiwxs&nav=MTVfezVFMzQ4MDRCLUZEQTQtNDlFQS1BRjYwLUZDQzZGODM4RUVFNX0)

# Insertion Sort
```c
void insertionSort(int *a, unsigned int n) {
    int i, j, v;
    int opcount = 0;
    for (i = 1; i < n; i++) {
        v = a[i];
        j = i - 1;
        // increment opcount whenever there is an element comparison
        while (++opcount && j >= 0 && a[j] > v) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = v;
    }
    printf("\n Operation count %d\n", opcount);
}

```

# DFS
```c
//
```
