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

TreeNode inorderSucc(TreeNode n) 
{
  if (n == null) return null;

  /* Found right children 
    -> return leftmost node of right subtree. */
  if (n.right != null) 
  {
    return leftMostChild(n.right);
  } 
  else 
  {
    TreeNode curr = n;
    TreeNode par = curr.parent;

    // Go up until we're on left instead of right
    while (par != null && par.left != curr) 
    {
      curr = par;
      par = par.parent;
    }
    return par;
  }
}

TreeNode leftMostChild(TreeNode n) 
{
  if (n == null) 
  {
    return null;
  }
  while (n.left != null) 
  {
    n = n.left;
  }
  return n;
}