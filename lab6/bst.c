#include <stdio.h> 
#include <stdlib.h>

#define MAX(a,b) ((a) > (b) ? (a) : (b))

int opcount = 0; // initialize the opcount variable 

struct node {
    int val;
    struct node *left, *right;
};

typedef struct node *NODE; 
NODE root = NULL;

NODE insert(int ele, NODE node);
int height(NODE node);
void printOpcount();

int main() {
    int choice, ele; 
    do {
        printf("1. Insert an element\n"); 
        printf("2. Find Height of BST\n"); 
        printf("3. Exit\n");
        printf("Please enter your choice: "); 
        scanf("%d", &choice); 

        switch(choice) {
            case 1: 
                printf("Insertion : Please enter an element\n"); 
                scanf("%d", &ele);
                root = insert(ele, root); 
                break;
            case 2: 
                printf("Height of BST : %d\n", height(root)); 
                printOpcount();
                break; 
            case 3: 
                break;
            default: 
                printf("Invalid choice. Please enter a valid choice\n");
                break;
        }
    } while(choice != 3);

    return 0;
}

NODE insert(int ele, NODE node) {
    NODE temp; 
    if(node == NULL) {
        temp = (NODE)malloc(sizeof(struct node)); 
        if (temp == NULL) {
            printf("Memory allocation failed. Exiting...\n");
            exit(EXIT_FAILURE);
        }
        temp->val = ele;
        temp->left = temp->right = NULL; 
        if(root == NULL)
            root = temp; 
        return temp;
    }
    else if(ele < node->val) {
        node->left = insert(ele, node->left); 
        return node;
    }
    else if(ele > node->val) {
        node->right = insert(ele, node->right); 
        return node;
    }
    else {
        printf("Duplicate element found while inserting. Insertion failed\n");
        return NULL;
    }
}

int height(NODE node) {
    opcount++; // increment opcount for the comparison statement 
    if(node == NULL)
        return -1;
    else
        return MAX(height(node->left), height(node->right)) + 1;
}

void printOpcount() {
    printf("Opcount = %d\n", opcount);
}
