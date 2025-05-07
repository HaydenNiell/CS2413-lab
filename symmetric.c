#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Helper function: checks whether t1 and t2 are mirror images.
bool isMirror(struct TreeNode* t1, struct TreeNode* t2) {
    // If both are NULL, they are mirrors.
    if (t1 == NULL && t2 == NULL) {
        return true;
    }
    // If only one is NULL, not mirrors.
    if (t1 == NULL || t2 == NULL) {
        return false;
    }
    // Both non-NULL: values must match, and the outer and inner subtrees must be mirrors.
    if (t1->val != t2->val) {
        return false;
    }
    return isMirror(t1->left,  t2->right)
        && isMirror(t1->right, t2->left);
}

// Main function: tree is symmetric if its left and right subtrees are mirrors.
bool isSymmetric(struct TreeNode* root) {
    if (root == NULL) {
        return true;
    }
    return isMirror(root->left, root->right);
}

// create a new TreeNode
struct TreeNode* newNode(int v) {
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    node->val   = v;
    node->left  = NULL;
    node->right = NULL;
    return node;
}

// Example usage
int main() {
    // Construct the tree [1,2,2,3,4,4,3]
    struct TreeNode* root  = newNode(1);
    root->left  = newNode(2);                     
    root->right = newNode(2);                   
    root->left->left   = newNode(3);           
    root->left->right  = newNode(4);
    root->right->left  = newNode(4);
    root->right->right = newNode(3);

    if (isSymmetric(root))
        printf("The tree is symmetric.\n");
    else
        printf("The tree is not symmetric.\n");

    return 0;
}
