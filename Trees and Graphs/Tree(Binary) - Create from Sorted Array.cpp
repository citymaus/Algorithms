/*
  Given a sorted (increasing order) array with unique integer elements, write an algorithm
  to create a binary search tree with minimal height.
*/
#include "Trees_and_Graphs.h"

TreeNode *addToMinimalBST(int arr[], int start, int end) {
  if (end < start) 
  {
    return NULL;
  }

  int mid = (start + end) / 2;
  TreeNode *n;
  n->data = arr[mid];
  n->left = addToMinimalBST(arr, start, mid - 1);
  n->right = addToMinimalBST(arr, mid + 1, end);
  return n;
}

TreeNode *createMinimalBST(int arr[]) {
  return addToMinimalBST(arr, 0, arr.size() - 1);
}	