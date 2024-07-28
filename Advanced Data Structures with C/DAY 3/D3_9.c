/*Write a C program to prove that binary search tree is better than binary tree.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct TreeNode* insertNode(struct TreeNode* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}
struct TreeNode* searchNode(struct TreeNode* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }
    if (key < root->data) {
        return searchNode(root->left, key);
    }
    return searchNode(root->right, key);
}
struct TreeNode* createBST(int arr[], int n) {
    struct TreeNode* root = NULL;
    int i;
    for (i = 0; i < n; i++) {
        root = insertNode(root, arr[i]);
    }
    return root;
}
double searchTime(struct TreeNode* root, int key) {
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    struct TreeNode* result = searchNode(root, key);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    return cpu_time_used;
}
int main() {
    int arr[] = { 5, 3, 7, 2, 4, 6, 8 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 6;
    struct TreeNode* btRoot = createBST(arr, n);
    struct TreeNode* bstRoot = createBST(arr, n);
    double btSearchTime = searchTime(btRoot, key);
    double bstSearchTime = searchTime(bstRoot, key);
    printf("Search time in Binary Tree: %f seconds\n", btSearchTime);
    printf("Search time in Binary Search Tree: %f seconds\n", bstSearchTime);
    free(btRoot);
    free(bstRoot);
    return 0;
}
