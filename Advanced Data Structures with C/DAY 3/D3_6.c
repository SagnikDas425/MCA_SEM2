/*6. Write a C program to sort a given set of integers using BST.*/
#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
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
void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}
void freeBST(struct TreeNode* root) {
    if (root != NULL) {
        freeBST(root->left);
        freeBST(root->right);
        free(root);
    }
}
int main() {
    struct TreeNode* root = NULL;
    int i, n, num;
    printf("Enter the number of integers: ");
    scanf("%d", &n);
    printf("Enter the integers:\n");
    for (i = 0; i < n; ++i) {
        scanf("%d", &num);
        root = insertNode(root, num);
    }
    printf("Sorted order: ");
    inorderTraversal(root);
    printf("\n");
    freeBST(root);
    return 0;
}
