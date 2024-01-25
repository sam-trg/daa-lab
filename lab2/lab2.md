![image](https://github.com/sam-trg/daa-lab/assets/90459209/e3e82ba0-05ee-4d3b-b403-6e8de5e117a8)

[Link to Data](https://learnermanipal-my.sharepoint.com/:x:/r/personal/samarth_mitblr2022_learner_manipal_edu/Documents/DAA-LAB.xlsx?d=w5297308de2a242258f09dad285d6c59e&csf=1&web=1&e=UqDABh&nav=MTVfezAwMDAwMDAwLTAwMDEtMDAwMC0wMDAwLTAwMDAwMDAwMDAwMH0)

# Code
```c
#include<stdio.h>

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

int main() {
    unsigned int m, n;

    printf("Enter the two numbers whose GCD has to be calculated: ");
    scanf("%d", &m);
    scanf("%d", &n);

    printf("GCD of two numbers using Euclid’s method is %d", EuclidGCD(m, n));
    
    return 0;
}
```
