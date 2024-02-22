#include <stdio.h>
#include <stdlib.h> // Include this header for malloc and exit

typedef struct node {
    int info;
    struct node *left, *right;
} NODE;

NODE* create(NODE *bnode, int x) {
    NODE *getnode;
    if (bnode == NULL) {
        bnode = (NODE*) malloc(sizeof(NODE));
        if (bnode == NULL) { // Check if memory allocation failed
            printf("Memory allocation failed\n");
            exit(1); // Exiting with failure status
        }
        bnode->info = x;
        bnode->left = bnode->right = NULL;
    } else if (x > bnode->info) {
        bnode->right = create(bnode->right, x);
    } else if (x < bnode->info) {
        bnode->left = create(bnode->left, x);
    } else {
        printf("Duplicate node\n");
        exit(0);
    }
    return bnode;
}

void inorder(NODE *ptr) {
    if (ptr != NULL) {
        inorder(ptr->left);
        printf("%5d", ptr->info);
        inorder(ptr->right);
    }
}

void postorder(NODE *ptr) {
    if (ptr != NULL) {
        postorder(ptr->left);
        postorder(ptr->right);
        printf("%5d", ptr->info);
    }
}

void preorder(NODE *ptr) {
    if (ptr != NULL) {
        printf("%5d", ptr->info);
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

int main() { // Changed void main() to int main()
    int ch, x;
    NODE *root = NULL;
    while (1) {
        printf("\n********************Output********************\n\n");
        printf(" Menu \n");
        printf(" 1. Insert\n 2. All traversals\n 3. Exit\n");
        printf("Enter your choice:");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter node (do not enter duplicate nodes):\n");
                scanf("%d", &x);
                root = create(root, x);
                break;
            case 2:
                printf("\nInorder traversal:\n");
                inorder(root);
                printf("\nPreorder traversal:\n");
                preorder(root);
                printf("\nPostorder traversal:\n");
                postorder(root);
                printf("\n\n*********************************************\n");
                break;
            case 3:
                exit(0);
            default: // Added default case to handle invalid input
                printf("Invalid choice\n");
        }
    }
    return 0; // Added return statement to indicate successful termination
}
