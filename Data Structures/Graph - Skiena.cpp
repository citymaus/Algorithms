#define MAXV		1000	/* maximum number of vertices */

typedef struct {
	int y;					/* adjacency info */
	int weight;				/* edge weight, if any */
	struct edgenode *next;	/* next edge in list */
} edgenode;

typedef struct {
	edgenode *edges[MAXV+1];	/* adjacency info */
	int degree[MAXV+1];			/* outdegree of each vertex */
	int nvertices;				/* number of vertices in graph */
	int nedges;					/* number of edges in graph */
	bool directed;				/* is teh graph directed? */
} graph;

initialize_graph(graph *g, bool directed)
{
	int i;		/* counter */
	
	g->nvertices = 0;
	g->nedges = 0;
	g->directed = directed;
	
	for (i = 1; i <= MAXV; i++) g->degree[i] = 0;
	for (i = 1; i <= MAXV; i++) g->edges[i] = NULL;
}

read_graph(graph *g, bool directed)
{
	int i;					/* counter */
	int m;					/* number of edges */
	int x, y;				/* vertices in edge (x, y) */
	
	initialize_graph(g, directed);
	
	scanf("%d %d", &(g->nvertices), &m);
	
	for (i = 1; i <= m; i++) {
		scanf("%d %d, &x, &y);
		insert_edge(g, x, y, directed);
	}
}

insert_edge(graph *g, int x, int y, bool directed)
{
	edgenode *p;					/* temporary pointer */
	
	p = malloc(sizeof(edgenode));	/*allocate edgenode storage */
	
	p->weight = NULL;
	p=>y = y;
	p->next = g->edges[x];
	
	g->edges[x] = p;				/* insert at head of list */
	g->degree[x]++;
	
	if (drected == FALSE) {
		insert_edge(g, y, x, TRUE);
	} else {
		g->nedges++;
	}
}

print_graph(graph *g)
{
	int i;
	edgenode *p;
	
	for (i = 1; i <=g->nvertices; i++) 
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

initialize_search(graph *g)
{
	int i;					/* counter */
	
	for (i = 1; i <= g->nvertices; i++)
	{
		processed[i] = discovered[i] = FALSE;
		parent[i] = -1;
	}
}

breadth_first_search(graph *g, int start)
{
	queue q;				/* queue of vertices to visit */
	int v; 					/* current vertex */
	int y;					/* successor vertex */
	edgenode *p;			/* temporary pointer */
	
	init_queue(&q);
	enqueue(&q, start);
	discovered[start] = TRUE;
	
	while(empty_queue(&q) == FALSE) 
	{
		v = dequeue(&q);
		process_vertex_early(v);
		processed[v] = TRUE;
		p = g->edges[v];
		while (p != NULL)
		{
			y = p->y;
			if ((processed[y] == FALSE) || g->directed)
			{
				process_edge(v, y);
			}
			if (discovered[y] == FALSE) 
			{
				enqueue(&q, y);
				discovered[y] = TRUE;
				parent[y] = v;
			}
			p = p->next;
		}
		process_vertex_late(v);
	}
}

process_vertex_late(int v)
{
}

process_vertex_early(int v)
{
	printf("rpocessed vertex %d\n", v);
}

process_edge(int x, int y)
{
	printf("processed edge (%d, %d)\n", x, y);
	nedges = nedges + 1;				/* get an accurate count of number of edges */
}

find_path(int start, int end, int parents[])
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

depth_first_search(graph *g, int v)
{
	edgenode *p;			/* temporary pointer */
	int y;					/* successor vertex */
	
	if (finished) return;	/* allow for search termination */
	
	discovered[v] = TRUE;
	time = time + 1;
	entry_time[v] = time;
	
	process_vertex_early(v);
	
	p = g->edges[v];
	while (p != NULL)
	{
		y = p->y;
		if (discovered[y] == FALSE)
		{
			parent[y] = v;
			process_edge(v, y);
			depth_first_search(g, y);
		}
		else if ((!processed[y] || (g->directed))
		{
			process_edge(v, y);
		}
		
		if (finished) return;
		
		p = p->next;
		
	}
	process_vertex_late(v);
	
	time = time + 1;
	exit_time[v] = time;
	
	processed[v] = TRUE;
}
