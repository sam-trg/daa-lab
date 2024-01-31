# Space and Time Complexity for Brute Force Approach

## Knapsack Problem
```c
int Knapsack(unsigned int *w, unsigned int *v, unsigned int n, unsigned int B) {
    
    unsigned int i, temp;
    unsigned int maxVal = 0, maxSequence = 0;
    unsigned int totalWeight, totalValue;
    
    unsigned int index = 0;
    
    // Generate bit array
    start = clock();
    for (i = 1; i < pow(2, n); i++) {
        ++opcount; // increment opcount for every possible subset
        
        // Compute total weight
        temp = i;
        totalWeight = totalValue = 0;
        index = 0;
        while (temp) {
            if (temp & 0x1) {
                totalWeight = totalWeight + w[index];
                totalValue = totalValue + v[index];
            }
            index++;
            temp = temp >> 1;
        }
        if (totalWeight <= B && totalValue > maxVal) {
            maxVal = totalValue;
            maxSequence = i;
        }
    }
    end = clock();
    return maxSequence;
}

```

![image](https://github.com/sam-trg/daa-lab/assets/90459209/f11d9a8a-7524-40ef-985a-459a77667309)

![image](https://github.com/sam-trg/daa-lab/assets/90459209/1caf3fcf-45ad-4e43-8e6d-395d19899a51)


[Right Click to open Data in New Tab](https://learnermanipal-my.sharepoint.com/:x:/r/personal/samarth_mitblr2022_learner_manipal_edu/Documents/DAA-LAB.xlsx?d=w5297308de2a242258f09dad285d6c59e&csf=1&web=1&e=LQoUTy&nav=MTVfezkzMzJCRDczLTg3MTgtNDk4Qy04RUJBLUQ1RDU5QUNCQjhDN30)

