/*


BREADTH-FIRST TRAVERSAL
Level-order
1. Init a queue, push the root
2. While the queue isn't empty, pop front node, print value
3. If not NULL, push left and right nodes to queue

DEPTH-FIRST TRAVERSAL
Pre-order
1. Display the data part of root element (or current element)
2. Traverse the left subtree by recursively calling the pre-order function.
3. Traverse the right subtree by recursively calling the pre-order function.

In-order (symmetric)
1. Traverse the left subtree by recursively calling the in-order function.
2. Display the data part of root element (or current element).
3. Traverse the right subtree by recursively calling the in-order function.

Post-order
1. Traverse the left subtree by recursively calling the post-order function.
2. Traverse the right subtree by recursively calling the post-order function.
3. Display the data part of root element (or current element).


*/

#include <cstdio>
#include <queue>
using namespace std;

struct node
{
    int mData;
    struct node *left;
    struct node *right;
};

// Breadth-first order
void printLevelOrder(node *root)
{
    if(NULL == root){
        return;
    }

    queue<node *> nodeQueue;
    nodeQueue.push(root);
    while(!nodeQueue.empty()){
        node *n = nodeQueue.front();
        nodeQueue.pop();    // pops the front
        if(NULL == n){
            continue;       // go back to top of the loop
        }
        printf("%s", n->mData + " ");
        nodeQueue.push(n->left);
        nodeQueue.push(n->right);
    }
}

void printInOrder(node *root)
{
    if (root != NULL)
    {
        printInOrder(root->left);
        printf("%s", root->mData + " ");
        printInOrder(root->right);
    }
}

void printPreOrder(node *root)
{
    if (root != NULL)
    {
        printf("%s", root->mData + " ");
        printInOrder(root->left);
        printInOrder(root->right);
    }
}

void printPostOrder(node *root)
{
    if (root != NULL)
    {
        printInOrder(root->left);
        printInOrder(root->right);
        printf("%s", root->mData + " ");
    }
}

node* newNode(int data, node *leftNode, node *rightNode)
{
    node *n = (node*)malloc(sizeof(node));
    n->mData = data;
    n->left = leftNode;
    n->right = rightNode;

    return n;
}

node* constructTree()
{
    /*
           9
          /  \
        5     15
      /  \   / \
     3   8   13 17
    / \ / \ / \ / \
    2 4 7 9 12 14 16 19

    */

    node *rootNode = newNode(9,
                            newNode(5,
                                newNode(3,
                                        newNode(2,NULL,NULL),
                                        newNode(4,NULL,NULL)),
                                newNode(8,
                                        newNode(7,NULL,NULL),
                                        newNode(9,NULL,NULL))),
                            newNode(15,
                                newNode(13,
                                        newNode(12,NULL,NULL),
                                        newNode(14,NULL,NULL)),
                                newNode(17,
                                        newNode(16,NULL,NULL),
                                        newNode(19,NULL,NULL))
                                    ));

    return rootNode;
}

void main() 
{
    printf("Level Order traversal of binary tree is \n");
    printLevelOrder(constructTree());
    printf("\n\nIn Order traversal of binary tree is \n");
    printInOrder(constructTree());
    printf("\n\nPre Order traversal of binary tree is \n");
    printPreOrder(constructTree());
    printf("\n\nPost Order traversal of binary tree is \n");
    printPostOrder(constructTree());
}