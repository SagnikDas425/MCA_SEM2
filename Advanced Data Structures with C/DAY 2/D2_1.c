/*Write a C program to create a binary tree using recursive function and display that level wise.*/
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct Node* insertNode(struct Node* root, int value) {
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
void displayLevelWise(struct Node* root, int level) {
    if (root == NULL) {
        return;
    }
    if (level == 1) {
        printf("%d ", root->data);
    } else if (level > 1) {
        displayLevelWise(root->left, level - 1);
        displayLevelWise(root->right, level - 1);
    }
}
int treeHeight(struct Node* root) {
    if (root == NULL) {
        return 0;
    } else {
        int leftHeight = treeHeight(root->left);
        int rightHeight = treeHeight(root->right);

        if (leftHeight > rightHeight) {
            return leftHeight + 1;
        } else {
            return rightHeight + 1;
        }
    }
}
void displayTree(struct Node* root) {
	int i;
    int height = treeHeight(root);
    for (i = 1; i <= height; i++) {
        printf("Level %d: ", i);
        displayLevelWise(root, i);
        printf("\n");
    }
}
int main() {
    struct Node* root = NULL;
    int i,n, value;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the values of nodes:\n");
    for ( i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insertNode(root, value);
    }
    printf("Binary Tree Level-wise:\n");
    displayTree(root);
    return 0;
}
