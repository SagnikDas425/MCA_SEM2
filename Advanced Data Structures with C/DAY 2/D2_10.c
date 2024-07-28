/*Write a C program to count number of siblings present in a binary tree.*/
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
int countSiblings(struct Node* root, int target) {
    if (root == NULL)
        return 0;
    struct Node* parent = NULL;
    struct Node* current = root;
    while (current != NULL && current->data != target) {
        parent = current;
        if (target < current->data)
            current = current->left;
        else
            current = current->right;
    }
    if (current == NULL || parent == NULL)
        return 0;
    int isLeftChild = (parent->left == current);
    return (isLeftChild ? (parent->right != NULL) : (parent->left != NULL));
}
int main() {
    struct Node* root = (struct Node*)malloc(sizeof(struct Node));
    root->data = 10;
    root->left = (struct Node*)malloc(sizeof(struct Node));
    root->left->data = 5;
    root->left->left = root->left->right = NULL;
    root->right = (struct Node*)malloc(sizeof(struct Node));
    root->right->data = 15;
    root->right->left = root->right->right = NULL;
    int targetValue = 5;
    int siblingsCount = countSiblings(root, targetValue);
    printf("Number of siblings for node with value %d: %d\n", targetValue, siblingsCount);
    free(root->left);
    free(root->right);
    free(root);
    return 0;
}
