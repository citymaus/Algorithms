/*
  Given a binary tree, design an algorithm which creates a linked list of all the nodes at
  each depth (e.g., if you have a tree with depth D, you'll have D linked lists).

  Time: O(N)
  Space: O(log N)
*/

#include <cstdio>
#include <vector>
#include <list>
using namespace std;

struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

void createLevelLinkedList(TreeNode *root, vector<list<TreeNode *>> lists, int level) 
{
  if (root == NULL) return; // base case

  list<TreeNode *> levellist;
  if (lists.size() == level) 
  { 
    // Level not contained in list
    //levellist.push_back(NULL);

    /* Levels are always traversed in order. So., if this is the
    * first time we've visited level i, we must have seen levels
    * 0 through i - 1. We can therefore safely add the level at
    * the end. */
    lists.push_back(levellist);
  } 
  else 
  {
      levellist = lists.at(level);
  }

  levellist.push_back(root);
  createLevelLinkedList(root->left, lists, level + 1);
  createLevelLinkedList(root->right, lists, level + 1);
}

vector<list<TreeNode *>> createLevelLinkedList(TreeNode *root) 
{
  vector<list<TreeNode *>> lists;
  createLevelLinkedList(root, lists, 0);
  return lists;
}