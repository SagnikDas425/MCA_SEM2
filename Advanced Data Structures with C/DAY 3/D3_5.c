/*5. Write a C program to take user name as input and display the sorted sequence of characters using BST.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
};
struct TreeNode* createNode(char value) {
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
struct TreeNode* insert(struct TreeNode* root, char value) {
    if (root == NULL) {
        return createNode(value);
    }
    char lowerValue = tolower(value);
    if (lowerValue < tolower(root->data)) {
        root->left = insert(root->left, value);
    }
    else if (lowerValue > tolower(root->data)) {
        root->right = insert(root->right, value);
    }
    return root;
}
void displayInOrder(struct TreeNode* root) {
    if (root != NULL) {
        displayInOrder(root->left);
        printf("%c ", root->data);
        displayInOrder(root->right);
    }
}
int main() {
    struct TreeNode* root = NULL;
    char name[100];
    int i;
    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    for (i = 0; i < strlen(name); i++) {
        if (isalpha(name[i])) {
            root = insert(root, name[i]);
        }
    }
    printf("Sorted sequence of characters in your name: ");
    displayInOrder(root);
    printf("\n");
    return 0;
}
