/* 
	Shortest Path - Dijkstra's Algorithm
	O(n^2) - 
	O(m + n*lg(n)) - priority queue data structures
*/
void dijkstra(graph *g, int start)
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
			if (distance[w] > (distance[v] + weight))
			{
				distance[w] = distance[v] + weight;
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