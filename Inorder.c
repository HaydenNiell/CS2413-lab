#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Helper function for recursive inorder traversal
void inorderHelper(struct TreeNode* root, int* result, int* returnSize) {
    if (root == NULL) return;

    inorderHelper(root->left, result, returnSize);
    result[(*returnSize)++] = root->val;
    inorderHelper(root->right, result, returnSize);
}

// Main function to return inorder traversal
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    int* result = (int*)malloc(100 * sizeof(int)); 
    inorderHelper(root, result, returnSize);
    return result;
}

// Helper to create a new TreeNode
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main() {
    // Build the Tree:
    struct TreeNode* root = createNode(5);
    root->left = createNode(3);
    root->right = createNode(8);

    root->left->left = createNode(1);
    root->left->right = createNode(4);
    root->left->right->right = createNode(6);

    root->right->right = createNode(10);
    // What the tree looks like:
    //         5
    //        / \
    //       3   8
    //      / \    \
    //     1   4    10
    //          \
    //           6

    
    int returnSize;
    int* result = inorderTraversal(root, &returnSize);

    printf("Inorder Traversal: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    
    free(result);
    free(root->left->left);
    free(root->left->right->right);
    free(root->left->right);
    free(root->left);
    free(root->right->right);
    free(root->right);
    free(root);

    return 0;
}
