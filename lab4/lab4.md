# Space and Time Complexity for Brute Force Approach

## Knapsack Problem
![image](https://github.com/sam-trg/daa-lab/assets/90459209/c34db559-d4df-49c5-8649-2426a1d2d3be)
![image](https://github.com/sam-trg/daa-lab/assets/90459209/4283d004-5a61-4498-acdc-566147a8712c)
```c
int Knapsack(unsigned int *w, unsigned int *v, unsigned int n, unsigned int B) {
    clock_t start = clock(), end;
    unsigned int i, t, W, V, maxV = 0, maxSeq = 0;

    for (i = 1; i < pow(2, n); ++i) {
        t = i, W = V = 0;
        for (unsigned int j = 0; t; t >>= 1, ++j) {
            if (t & 1) {
                W += w[j];
                V += v[j];
            }
        }
        if (W <= B && V > maxV)
            maxV = V, maxSeq = i;
    }

    end = clock();
    printf("Execution Time: %.6f seconds\n", ((double)(end - start)) / CLOCKS_PER_SEC);
    return maxSeq;
}

```



## Assignment Problem
![image](https://github.com/sam-trg/daa-lab/assets/90459209/4f7ebd51-27c8-44fc-992b-fbde7cbbe8fc)
![image](https://github.com/sam-trg/daa-lab/assets/90459209/cdc864c9-e8d8-4ec3-a815-a83e2433e83a)
```c
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

```

[Right Click to open Data in New Tab](https://learnermanipal-my.sharepoint.com/:x:/r/personal/samarth_mitblr2022_learner_manipal_edu/Documents/DAA-LAB.xlsx?d=w5297308de2a242258f09dad285d6c59e&csf=1&web=1&e=LQoUTy&nav=MTVfezkzMzJCRDczLTg3MTgtNDk4Qy04RUJBLUQ1RDU5QUNCQjhDN30)
