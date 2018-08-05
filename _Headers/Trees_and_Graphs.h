#ifndef TREES_AND_GRAPHS_H
#define TREES_AND_GRAPHS_H

#include <cstdio>
#include <climits>
#include <cmath>      // abs
#include <algorithm>  // max

struct TreeNode {
	int data;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) : data(x), left(NULL), right(NULL) {}
};

struct Node
{
	int data;
	struct Node *next;
};
enum State { Unvisited, Visited, Visiting};

template<typename Key, typename Value>
class RedBlack
{
	enum Colour
	{
		RED,
		BLACK
	};

	struct RedBlackNode
	{
		Colour colour;
		Key key;
		Value value;
		RedBlackNode *parent;
		RedBlackNode *left;
		RedBlackNode *right;
	};

	RedBlackNode *root;
	
public:
	RedBlack();
	~RedBlack();
	void Insert(const Key& key, const Value& value);
	Value& Find(const Key& key);
	void Delete(const Key& key);
	void Dump();
private:
	void RotateLeft(RedBlackNode *x);
	void RotateRight(RedBlackNode *y);
	void Transplant(RedBlackNode *dest, RedBlackNode *src);
	RedBlackNode *Minimum(RedBlackNode *tree);
	void Dump(RedBlackNode *node, int tabs);
	void DeleteNode(RedBlackNode *node);
};

#define MAXV		1000	/* maximum number of vertices */
struct edgenode {
	int y;					  /* vertex adjacency info */
	int weight;				/* edge weight, if any */
	struct edgenode *next;	/* next edge in list */
};

struct graph {
	edgenode *edges[MAXV + 1];	/* adjacency info */
	int degree[MAXV + 1];			/* outdegree of each vertex */
	int nvertices;				/* number of vertices in graph */
	int nedges;					/* number of edges in graph */
	bool directed;				/* is the graph directed? */
};

struct set_union {
	int p[SET_SIZE + 1];		/* parent element */
	int size[SET_SIZE + 1];		/* number of elements in subtree i */
	int n;						/* number of elements in set */
};

/*
bool breadth_first_search(graph g, Node start, Node end);
int Floyds_Has_Cycle(Node* head);
*/
#endif