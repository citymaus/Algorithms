/*
  Given a binary tree, design an algorithm which creates a linked list of all the nodes at
  each depth (e.g., if you have a tree with depth D, you'll have D linked lists).

  Time: O(N)
  Space: O(log N)
*/

void createLevelLinkedList(TreeNode *root, ArrayList<LinkedList<TreeNode *>> lists, int level) 
{
  if (root == null) return; // base case

  LinkedList<TreeNode *> list = null;
  if (lists.size() == level) 
  { 
    // Level not contained in list
    list = new LinkedList<TreeNode *>();

    /* Levels are always traversed in order. So., if this is the
    * first time we've visited level i, we must have seen levels
    * 0 through i - 1. We can therefore safely add the level at
    * the end. */
    lists.add(list);
  } 
  else 
  {
    list = lists.get(level);
  }

  list.add(root);
  createLevelLinkedList(root->left, lists, level + 1);
  createLevelLinkedList(root->right, lists, level + 1);
}

ArrayList<LinkedList<TreeNode *>> createLevelLinkedList(TreeNode *root) 
{
  ArrayList<LinkedList<TreeNode *>> lists = new ArrayList<LinkedList<TreeNode *>>();
  createLevelLinkedList(root, lists, 0);
  return lists;
}