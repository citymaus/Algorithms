#include <cmath>      // abs
#include <algorithm>  // max
using namespace std;

/*
  Implement a function to check if a binary tree is balanced. For the purposes of this
  question, a balanced tree is defined to be a tree such that the heights of the two
  subtrees of any node never differ by more than one.
*/

struct TreeNode {
  int data;
  struct TreeNode *left;
  struct TreeNode *right;
};

int checkHeight(TreeNode *root) 
{
  if (root == NULL) 
  {
    return 0; // Height of 0
  }

  /* Check if left is balanced. */
  int leftHeight = checkHeight(root->left);

  if (leftHeight == -1) 
  {
    return -1; // Not balanced
  }

  /* Check if right is balanced. */
  int rightHeight = checkHeight(root->right);

  if (rightHeight == -1) 
  {
    return -1; // Not balanced
  }

  /* Check if current node is balanced. */
  int heightDiff = leftHeight - rightHeight;

  if (abs(heightDiff) > 1) 
  {
      return -1; // Not balanced
  } 
  else 
  {
    /* Return height */
    return max(leftHeight, rightHeight) + 1;
  }
}

bool isBalanced(TreeNode *root) 
{
  if (checkHeight(root) == -1) {
    return false;
  } else {
    return true;
  }
}
