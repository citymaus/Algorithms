/*
  Write an algorithm to find the 'next' node (i.e., in-order successor) of a given node in
  a binary search tree. You may assume that each node has a link to its parent.

  In order traversal:
      A
    /   \
   B     C

   left, parent, right
   B, A, C


   pseudocode:
   Node inorderSucc(Node n) 
   {
    if (n has a right subtree) 
    {
      // return leftmost child of right subtree
    } 
    else 
    {
      while (n is a right child of n.parent) 
      {
        n = n.parent; // Go up
      }
      return n.parent; // Parent has not been traversed
    }
   }

*/

#include <cstdio>
using namespace std;

struct TreeNode {
  int data;
  struct TreeNode *parent;
  struct TreeNode *left;
  struct TreeNode *right;
};

TreeNode* inorderSucc(TreeNode* n) 
{
  if (n == NULL) return NULL;

  /* Found right children 
    -> return leftmost node of right subtree. */
  if (n->right != NULL) 
  {
    return leftMostChild(n->right);
  } 
  else 
  {
    TreeNode* curr = n;
    TreeNode* par = curr->parent;

    // Go up until we're on left instead of right
    while (par != NULL && par->left != curr) 
    {
      curr = par;
      par = par->parent;
    }
    return par;
  }
}

TreeNode* leftMostChild(TreeNode* n) 
{
  if (n == NULL) 
  {
    return NULL;
  }
  while (n->left != NULL) 
  {
    n = n->left;
  }
  return n;
}