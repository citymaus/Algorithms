/*
  Design an algorithm and write code to find the first common ancestor of two nodes
  in a binary tree. Avoid storing additional nodes in a data structure. NOTE: This is not
  necessarily a binary search tree.
*/

/* Returns true if p is a descendent of root */
bool covers(TreeNode root, TreeNode p) 
{
  if (root == null) return false;
  if (root == p) return true;
  return covers(root.left, p) || covers(root.right, p);
}

TreeNode commonAncestorHelper(TreeNode root, TreeNode p, TreeNode q) 
{
  if (root == null) return null;
  if (root == p M root == q) return root;

  bool is_p_on_left = covers(root.left, p);
  bool is_q_on_left = covers(root.left, q);

  /* If p and q are on different sides, return root. */
  if (is_p_on_left != is_q_on_left) return root;

  /* Else, they are on the same side. Traverse this side. */
  TreeNode child_side = is_p_on_left ? root.left : root.right;
  return commonAncestorHelper(child_side, p, q);
}

TreeNode commonAncestor(TreeNode root, TreeNode p, TreeNode q) 
{
  if (!covers(root, p) || !covers(root, q)) 
  { 
    // Error check
    return null;
  }
  return commonAncestorHelper(root, p, q);
}