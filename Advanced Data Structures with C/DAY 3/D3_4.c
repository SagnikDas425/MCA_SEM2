/*Write a C program to search an element in a BST and show the result.*/
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
struct TreeNode* search(struct TreeNode* root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }
    if (value < root->data) {
        return search(root->left, value);
    }
    else {
        return search(root->right, value);
    }
}
int main() {
    struct TreeNode* root = NULL;
    int value, searchValue;
    char choice;
    do {
        printf("Enter a value to insert into the BST: ");
        scanf("%d", &value);
        root = insert(root, value);
        printf("Do you want to insert another value? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');
    printf("Enter the value to search in the BST: ");
    scanf("%d", &searchValue);
    struct TreeNode* result = search(root, searchValue);
    if (result != NULL) {
        printf("%d is found in the BST.\n", searchValue);
    } else {
        printf("%d is not found in the BST.\n", searchValue);
    }
    return 0;
}
