/*1. Write a C program to create a binary search tree using recursive function and display that.*/
#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
struct TreeNode* insert(struct TreeNode* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}
void displayInOrder(struct TreeNode* root) {
    if (root != NULL) {
        displayInOrder(root->left);
        printf("%d ", root->data);
        displayInOrder(root->right);
    }
}
int main() {
    struct TreeNode* root = NULL;
    int value;
    char choice;
    do {
        printf("Enter a value to insert into the BST: ");
        scanf("%d", &value);
        root = insert(root, value);
        printf("Do you want to insert another value? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');
    printf("Binary Search Tree (Inorder traversal): ");
    displayInOrder(root);
    printf("\n");
    return 0;
}
