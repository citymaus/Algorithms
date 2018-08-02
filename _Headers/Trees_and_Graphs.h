#include <cstdio>
#include <climits>
#include <cmath>      // abs
#include <algorithm>  // max

struct TreeNode {
	int data;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct Node
{
	int data;
	struct Node *next;
};
enum State { Unvisited, Visited, Visiting};

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
