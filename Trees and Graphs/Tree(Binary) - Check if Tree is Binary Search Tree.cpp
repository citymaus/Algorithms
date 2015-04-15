/*
  Implement a function to check if a binary tree is a binary search tree.

  Time: O(N)
  Space: O(log N)
*/

struct TreeNode {
  int data;
  struct TreeNode *left;
  struct TreeNode *right;
};

bool isBST(TreeNode *n) 
{
  return checkBST(n, MIN_INT, MAX_INT);
}

bool checkBST(TreeNode *n, int min, int max) 
{
  if (n == null) 
  {
    return true;
  }

  if (n->data <= min || n->data > max) 
  {
    return false;
  }

  if (!checkBST(n->left, min, n->data) || !checkBST(n->right, n->data, max)) 
  {
    return false;
  }

  return true;
}