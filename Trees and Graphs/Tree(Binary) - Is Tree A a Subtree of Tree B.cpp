/*
  You have two very large binary trees: T1, with millions of nodes, and T2, with
  hundreds of nodes. Create an algorithm to decide if T2 is a subtree ofTl.
  A tree T2 is a subtree of T1 if there exists a node n in T1 such that the subtree ofn
  is identical to T2. That is, if you cut off the tree at node n, the two trees would be
  identical.

  Time: O(nm)
  Space: O(log n + log m)
*/

bool containsTree(TreeNode tl, TreeNode t2) 
{
  if (t2 == null) 
  { // The empty tree is always a subtree
    return truej
  }
  return subTree(tl, t2);
}

bool subTree(TreeNode rl, TreeNode r2) 
{
  if (rl == null) 
  {
    return false; II big tree empty & subtree still not found.
  }

  if (rl.data == r2.data) 
  {
    if (matchTree(rl,r2)) return true;
  }
  return (subTree(rl.left, r2) || subTree(rl.right, r2));
}

bool matchTree(TreeNode rl, TreeNode r2) 
{
  if (r2 == null && rl == null) // if both are empty
    return true; // nothing left in the subtree

  // if one, but not both, are empty
  if (rl == null || r2 == null) 
  {
    return false;
  }

  if (rl.data != r2.data)
  {
    return false; // data doesn't match
  }

  return (matchTree(rl.leftJ r2.1eft) && matchTree(rl.right, r2.right));
}