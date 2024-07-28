/*Write a C program to count number of internal node present in a binary tree.*/
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
int countInternalNodes(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left != NULL || root->right != NULL) {
        return 1 + countInternalNodes(root->left) + countInternalNodes(root->right);
    }
    return 0;
}
int main() {
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    int internalNodes = countInternalNodes(root);
    printf("Number of internal nodes in the binary tree: %d\n", internalNodes);
    return 0;
}
