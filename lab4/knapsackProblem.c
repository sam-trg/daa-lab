#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

clock_t start,end;
int opcount=0; // Intialize the opcount variable

int Knapsack(unsigned int *w, unsigned int *v, unsigned int n, unsigned int B) {
    
    unsigned int i,temp;
    unsigned int maxVal=0, maxSequence=0;
    unsigned int totalWeight, totalValue;
    
    unsigned int index=0;
    //Generate bit array
    start = clock();
    for(i=1;i<pow(2,n);i++)
    {
    ++opcount; //increment opcount for every possible subsets
    //Compute total weight
    temp = i;
    totalWeight=totalValue=0;
    index=0;
    while(temp) {
    if(temp & 0x1) {
    totalWeight = totalWeight + w[index];
    totalValue = totalValue + v[index];
    }
    index++;
    temp = temp >> 1;
    }
    if(totalWeight <= B && totalValue > maxVal) {
        maxVal = totalValue;
    maxSequence = i;
    }
    }
    end = clock();
    return maxSequence;
}


int main() {
    
    unsigned int *v,*w, i,n,knaps, B;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    v = (unsigned int *)calloc(n, sizeof(unsigned int));
    w = (unsigned int *) calloc(n, sizeof(unsigned int));
    printf("Please enter the weights: \n");
    for(i=0;i<n;i++) {
        printf("Weight %d: ", i+1);
        scanf(" %d",&w[i]);
    }
    printf("Please enter the values: \n");
    for(i=0;i<n;i++) {
        printf("Value %d: ", i+1);
        scanf("%d",&v[i]);
    }
    printf("Please enter the Knapsack capacity: ");
        scanf("%d", &B);
    
    printf("\n");
    knaps = Knapsack(w,v,n,B);
    printf("Knapsack contains the following items: \n\n");
    i=0;
    while(knaps) {
        if(knaps & 0X1)
            printf("Item %u Value %u\n", (i+1), v[i]);
        i++;
        knaps = knaps >> 1;
    }
    
    printf("\n Operation count = %d\n",opcount);
    printf(" Time elapsed = %f", (double)(end-start)/CLOCKS_PER_SEC);
    return 0;
}
