/*
  Given a sorted (increasing order) array with unique integer elements, write an algorithm
  to create a binary search tree with minimal height.
*/

struct TreeNode {
  int data;
  struct TreeNode *left;
  struct TreeNode *right;
};

TreeNode *addToMinimalBST(int arr[], int start, int end) {
  if (end < start) 
  {
    return null;
  }

  int mid = (start + end) / 2;
  TreeNode *n;
  n->data = arr[mid];
  n->left = addToMinimalBST(arr start, mid - 1);
  n->right = addToMinimalBST(arr, mid + 1, end);
  return n;
}

TreeNode *createMinimalBST(int array[]) {
  return addToMinimalBST(array, 0, array.length - 1);
}