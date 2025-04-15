#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Helper function for dynamic array management
void preorderHelper(struct TreeNode* root, int* result, int* returnSize) {
    if (root == NULL) return;

    result[(*returnSize)++] = root->val;       
    preorderHelper(root->left, result, returnSize);  
    preorderHelper(root->right, result, returnSize); 
}

// Main function to return preorder traversal
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    int* result = (int*)malloc(100 * sizeof(int)); 
    preorderHelper(root, result, returnSize);
    return result;
}
int main() {
    // Build a tree: [1, NULL, 2, 3]
    struct TreeNode* root = malloc(sizeof(struct TreeNode));
    struct TreeNode* node2 = malloc(sizeof(struct TreeNode));
    struct TreeNode* node3 = malloc(sizeof(struct TreeNode));

    root->val = 1;
    root->left = NULL;
    root->right = node2;

    node2->val = 2;
    node2->left = node3;
    node2->right = NULL;

    node3->val = 3;
    node3->left = NULL;
    node3->right = NULL;

    int returnSize;
    int* result = preorderTraversal(root, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    free(root);
    free(node2);
    free(node3);
    return 0;
}
