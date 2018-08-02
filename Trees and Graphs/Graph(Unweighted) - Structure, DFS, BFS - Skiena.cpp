#include <cstdio>
#include <iostream>
#include <queue>
#include "Trees_and_Graphs.h"
using namespace std;

void initialize_graph(graph *g, bool directed)
{
	int i;		/* counter */
	
	g->nvertices = 0;
	g->nedges = 0;
	g->directed = directed;
	
	for (i = 1; i <= MAXV; i++) g->degree[i] = 0;
	for (i = 1; i <= MAXV; i++) g->edges[i] = NULL;
}

void read_graph(graph *g, bool directed)
{
	int i;					/* counter */
	int m;					/* number of edges */
	int x, y;				/* vertices in edge (x, y) */
	
	initialize_graph(g, directed);
	
	scanf("%d %d", &(g->nvertices), &m);
	
	for (i = 1; i <= m; i++) {
		scanf("%d %d", &x, &y);
		insert_edge(g, x, y, directed);
	}
}

void insert_edge(graph *g, int x, int y, bool directed)
{
	edgenode *p;					/* temporary pointer */
	
	p = (edgenode *)malloc(sizeof(edgenode));	/*allocate edgenode storage */
	
	p->weight = NULL;
	p->y = y;
	p->next = g->edges[x];
	
	g->edges[x] = p;				/* insert at head of list */
	g->degree[x]++;
	
	if (directed == false) {
		insert_edge(g, y, x, true);
	} else {
		g->nedges++;
	}
}

void print_graph(graph *g)
{
	int i;
	edgenode *p;
	
  printf("vertex: [vertices connected]\n");
	for (i = 1; i <= g->nvertices; i++) 
	{
		printf("%d: ", i);
		p = g->edges[i];
		while (p != NULL) 
		{
			printf(" %d", p->y);
			p = p->next;
		}
		printf("\n");
	}
}

bool processed[MAXV+1];		/* which vertices have been processed */
bool discovered[MAXV+1];	/* which vertices have been found */
int parent[MAXV+1];			/* discovery relation */

void initialize_search(graph *g)
{
	int i;					/* counter */
	
	for (i = 1; i <= g->nvertices; i++)
	{
		processed[i] = discovered[i] = false;
		parent[i] = -1;
	}
}

void breadth_first_search(graph *g, int start)
{
	queue<int> q;				/* queue of vertices to visit */
	int v; 					/* current vertex */
	int y;					/* successor vertex */
	edgenode *p;			/* temporary pointer */
	
	//init_queue(&q);
	//enqueue(&q, start);
	q.push(start);      /* push to back */
  discovered[start] = true;
	
	while(q.empty() == false) 
	{
		//v = dequeue(&q);
		v = q.front();
    q.pop();        /* pop the front */
    process_vertex_early(v);
		processed[v] = true;
		p = g->edges[v];
		while (p != NULL)
		{
			y = p->y;
			if ((processed[y] == false) || g->directed)
			{
				process_edge(v, y);
			}
			if (discovered[y] == false) 
			{
				//enqueue(&q, y);
        q.push(y);      /* push to back */
				discovered[y] = true;
				parent[y] = v;
			}
			p = p->next;
		}
		process_vertex_late(v);
	}
}

void process_vertex_late(int v)
{
}

void process_vertex_early(int v)
{
	printf("processed vertex %d\n", v);
}

void process_edge(int x, int y)
{
	printf("processed edge (%d, %d)\n", x, y);
	nedges = nedges + 1;				/* get an accurate count of number of edges */
}

void find_path(int start, int end, int parents[])
{
	if ((start == end) || (end == -1))
	{
		printf("\n%d", start);
	}
	else
	{
		find_path(start, parents[end], parents);
		printf(" %d", end);
	}
}

void depth_first_search(graph *g, int v)
{
	edgenode *p;			/* temporary pointer */
	int y;					/* successor vertex */
	
	if (finished) return;	/* allow for search termination */
	
	discovered[v] = true;
	time = time + 1;
	entry_time[v] = time;
	
	process_vertex_early(v);
	
	p = g->edges[v];
	while (p != NULL)
	{
		y = p->y;
		if (discovered[y] == false)
		{
			parent[y] = v;
			process_edge(v, y);
			depth_first_search(g, y);
		}
		else if ((!processed[y]) || (g->directed))
		{
			process_edge(v, y);
		}
		
		if (finished) return;
		
		p = p->next;
		
	}
	process_vertex_late(v);
	
	time = time + 1;
	exit_time[v] = time;
	
	processed[v] = true;
}
