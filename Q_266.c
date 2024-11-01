#include <string.h>
// Definition for a binary tree node.
struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

struct TreeNode *invertTree(struct TreeNode *root) {
  if (root == NULL) {
    return root;
  } else {
    struct TreeNode *temp;
    temp = root->right;
    root->right = root->left;
    root->left = temp;
    root->right = invertTree(root->right);
    root->left = invertTree(root->left);
  }
  return root;
}
