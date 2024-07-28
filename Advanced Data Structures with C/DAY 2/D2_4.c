/*4. Write a C program to identify the height of a binary tree.*/
#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (newNode != NULL) {
        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}
struct TreeNode* insertNode(struct TreeNode* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }

    return root;
}
int treeHeight(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);
    return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
}
void freeTree(struct TreeNode* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}
int main() {
    struct TreeNode* root = NULL;
    int nodeValue;
    char choice;
    do {
        printf("Input a value to insert into the binary tree (enter 0 to stop): ");
        scanf("%d", &nodeValue);
        if (nodeValue != 0) {
            root = insertNode(root, nodeValue);
        }
    } while (nodeValue != 0);
    int height = treeHeight(root);
    printf("\nHeight of the Binary Tree: %d\n", height);
    freeTree(root);
    return 0;
}
