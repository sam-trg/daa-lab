![image](https://github.com/sam-trg/daa-lab/assets/90459209/8c6c5cb7-0ca8-4cb0-adba-ac8758c53834)


[Right Click to open Data in New Tab](https://learnermanipal-my.sharepoint.com/:x:/r/personal/samarth_mitblr2022_learner_manipal_edu/Documents/DAA-LAB.xlsx?d=w5297308de2a242258f09dad285d6c59e&csf=1&web=1&e=UqDABh&nav=MTVfezAwMDAwMDAwLTAwMDEtMDAwMC0wMDAwLTAwMDAwMDAwMDAwMH0)

# Code
```c
unsigned int EuclidGCD(unsigned int m, unsigned int n) {
    unsigned int r;
    int opcount = 0; // variable to count how many times the basic operation executes.

    while (n != 0) {
        opcount++;
        r = m % n;
        m = n;
        n = r;
    }

    printf("Operation count= %d\n", opcount);
    return m;
}
```
