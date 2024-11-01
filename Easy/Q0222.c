#include <math.h>
#include <string.h>
// Definition for a binary tree node.
struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

int countNodes(struct TreeNode *root) {
  if (root == NULL)
    return 0;

  struct TreeNode *leftside = root, *rightside = root;
  int l = 1, r = 1;
  while ((leftside = leftside->left))
    l++;
  while ((rightside = rightside->right))
    r++;

  if (l == r)
    return pow(2, l) - 1;
  return 1 + countNodes(root->left) + countNodes(root->right);
}
