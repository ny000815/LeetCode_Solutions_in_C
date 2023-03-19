#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

struct TreeNode* createNode(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int maxDepth(TreeNode* root);

int main() {
    TreeNode* root = createNode(3);
    root->left = createNode(9);
    root->right = createNode(20);
    root->right->left = createNode(15);
    root->right->right = createNode(7);
    int depth = maxDepth(root);
    printf("Maximum depth of binary tree: %d\n", depth);
    free(root->left);
    free(root->right->left);
    free(root->right->right);
    free(root->right);
    free(root);
    return 0;
}

int maxDepth(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int left_depth = maxDepth(root->left);
    int right_depth = maxDepth(root->right);
    if (left_depth > right_depth) {
        return left_depth + 1;
    } else {
        return right_depth + 1;
    }
}



