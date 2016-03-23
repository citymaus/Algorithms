#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

/* Program to find height of the tree by Iterative Method */
 
// A Binary Tree Node
struct TreeNode {
  int data;
  struct TreeNode *left;
  struct TreeNode *right;
};

// Recursive method to find height of Binary Tree
/* Compute the "maxDepth" of a tree -- the number of 
    nodes along the longest path from the root node 
    down to the farthest leaf node.*/
int maxDepth(TreeNode* node) 
{
   if (node==NULL) 
       return 0;
   else
   {
       /* compute the depth of each subtree */
       int lDepth = maxDepth(node->left);
       int rDepth = maxDepth(node->right);
 
       /* use the larger one */
       if (lDepth > rDepth) 
           return(lDepth+1);
       else return(rDepth+1);
   }
} 
 
// Iterative method to find height of Binary Tree
int treeHeight(TreeNode *root)
{
    // Base Case
    if (root == NULL)
        return 0;
 
    // Create an empty queue for level order traversal
    queue<TreeNode *> q;
 
    // Enqueue Root and initialize height
    q.push(root);
    int height = 0;
 
    while (1)
    {
        // nodeCount (queue size) indicates number of nodes
        // at current lelvel.
        int nodeCount = q.size();
        if (nodeCount == 0)
            return height;
 
        height++;
 
        // Dequeue all nodes of current level and Enqueue all
        // nodes of next level
        while (nodeCount > 0)
        {
            TreeNode *node = q.front();
            q.pop();
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
            nodeCount--;
        }
    }
}
 
// Utility function to create a new tree node
TreeNode* newNode(int data)
{
    TreeNode *temp = new TreeNode;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
 
// Driver program to test above functions
int main()
{
    // Let us create binary tree shown in above diagram
    TreeNode *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
 
    cout << "Height of tree is " << treeHeight(root);
    return 0;
}