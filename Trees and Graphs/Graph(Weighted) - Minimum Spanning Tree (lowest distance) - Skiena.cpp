#define MAXV		1000	/* maximum number of vertices */

struct edgenode {
	int y;					/* adjacency info */
	int weight;				/* edge weight, if any */
	struct edgenode *next;	/* next edge in list */
};

struct graph {
	edgenode *edges[MAXV+1];	/* adjacency info */
	int degree[MAXV+1];			/* outdegree of each vertex */
	int nvertices;				/* number of vertices in graph */
	int nedges;					/* number of edges in graph */
	bool directed;				/* is the graph directed? */
};

/* 
	Minimum Spanning Tree - Prim's Algorithm
	O(n^2) - 
	O(m + n*lg(n)) - priority queue data structures
*/
void prim(graph *g, int start)
{
	int i;					/* counter */
	edgenode *p;			/* temporary pointer */
	bool intree[MAXV+1];	/* is the vertex in the tree yet? */
	int distance[MAXV+1];	/* cost of adding to tree */
	int v;					/* current vertex to process */
	int w;					/* candidate next vertex */
	int weight;				/* edge weight */
	int dist;				/* best current distance from start */
	
	for (i = 1; i <= g->nvertices; i++)
	{
		intree[i] = FALSE;
		distance[i] = MAXINT;
		parent[i] = -1;
	}
	
	distance[start] = 0;
	v = start;
	
	while (intree[v] == FALSE)
	{
		intree[v] = TRUE;
		p = g->edges[v];
		while (p != NULL) 
		{
			w = p->y;
			weight = p->weight;
			if ((distance[w] > weight) && (intree[w] == FALSE))
			{
				distance[w] = weight;
				parent[w] = v;
			}
			p = p->next;
		}
		
		v = 1;
		dist = MAXINT;
		for (i = 1; i <= g->nvertices; i++)
		{
			if ((intree[i] == FALSE) && (dist > distance[i]))
			{
				dist = distance[i];
				v = i;
			}
		}
	}
}

/* 
	Minimum Spanning Tree - Kruskal's Algorithm
	(better for sparse graphs)
	O(n^2) - 
	O(m + n*lg(n)) - priority queue data structures
*/
void kruskal(graph *g)
{
	int i;					/* counter */
	set_union s;			/* set union data structure */
	edge_pair e[MAXV+1];	/* array of edges data structure */
	bool weight_compare();
	
	set_union_init(&s, g->nvertices);
	
	to_edge_array(g, e);	/* sort edges by increasing cost */
	qsort(&e, g->nedges, sizeof(edge_pair), weight_compare);
	
	for (i = 0; i < (g->nedges); i++)
	{
		if (!same_component(s, e[i].x, e[i].y))
		{
			printf("edge (%d, %d) in MST]n", e[i].x, e[i].y);
			union_sets(&s, e[i].x, e[i].y);
		}
	}
}

struct set_union {
	int p[SET_SIZE+1];		/* parent element */
	int size[SET_SIZE+1];	/* number of elements in subtree i */
	int n;					/* number of elements in set */
};

