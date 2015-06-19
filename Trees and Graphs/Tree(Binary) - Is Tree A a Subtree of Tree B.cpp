/*
  You have two very large binary trees: T1, with millions of nodes, and T2, with
  hundreds of nodes. Create an algorithm to decide if T2 is a subtree ofTl.
  A tree T2 is a subtree of T1 if there exists a node n in T1 such that the subtree ofn
  is identical to T2. That is, if you cut off the tree at node n, the two trees would be
  identical.

  Time: O(nm)
  Space: O(log n + log m)
*/

#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

struct TreeNode {
  int data;
  struct TreeNode *left;
  struct TreeNode *right;
};

bool containsTree(TreeNode* tl, TreeNode* t2) 
{
  if (t2 == NULL) 
  { // The empty tree is always a subtree
    return true;
  }
  return subTree(tl, t2);
}

bool subTree(TreeNode* r1, TreeNode* r2) 
{
  if (r1 == NULL) 
  {
    return false; // big tree empty & subtree still not found.
  }

  if (r1->data == r1->data) 
  {
    if (matchTree(r1, r2)) return true;
  }
  return (subTree(r1->left, r2) || subTree(r1->right, r2));
}

bool matchTree(TreeNode* r1, TreeNode* r2) 
{
  if (r2 == NULL && r1 == NULL) // if both are empty
    return true; // nothing left in the subtree

  // if one, but not both, are empty
  if (r1 == NULL || r2 == NULL) 
  {
    return false;
  }

  if (r1->data != r2->data)
  {
    return false; // data doesn't match
  }

  return (matchTree(r1->left, r2->left) && matchTree(r1->right, r2->right));
}