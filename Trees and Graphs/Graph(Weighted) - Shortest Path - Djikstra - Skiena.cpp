/* 
	Shortest Path - Dijkstra's Algorithm

  BFS

	O(n^2) - 
	O(m + n*lg(n)) - priority queue data structures
*/
#include "Trees_and_Graphs.h"

int dijkstra(graph *g, int start, int end = -1)
{
	int i;					/* counter */
	edgenode *curr_edge;	/* temporary pointer */
	bool visited[MAXV+1];	/* is the vertex in the tree yet? */
	int distance[MAXV+1];	/* cost of adding to tree */
	int parent[MAXV+1];
	int current_vertex;		/* current vertex to process */
	int next_vertex;		/* candidate next vertex */
	int weight;				/* edge weight */
	int dist;				/* best current distance from start */
	
	for (i = 1; i <= g->nvertices; i++)
	{
		visited[i] = false;
		distance[i] = INT_MAX;
		parent[i] = -1;
	}
	
	distance[start] = 0;
	current_vertex = start;
	
	while (visited[current_vertex] == false)
	{
		visited[current_vertex] = true;
		curr_edge = g->edges[current_vertex];

    // Visit all neighbors
		while (curr_edge != NULL) 
		{
			next_vertex = curr_edge->y;
			weight = curr_edge->weight;
      
			if (distance[next_vertex] > (distance[current_vertex] + weight))
			{
				distance[next_vertex] = distance[current_vertex] + weight;
				parent[next_vertex] = current_vertex;
			}

      // Check if destination node has been found
      if (next_vertex == end)
      {
        break;
      }

      curr_edge = curr_edge->next;
		}
		
		current_vertex = 1;
		dist = INT_MAX;
		for (i = 1; i <= g->nvertices; i++)
		{
			if ((visited[i] == false) && (dist > distance[i]))
			{
				dist = distance[i];
				current_vertex = i;
			}
		}
	}   // while (visited[current_vertex] == FALSE)

  if (end != -1)
  {
    return distance[end]; // Return shortest path between two nodes
  }
  else
  {
    return dist;      // Return overall shortest path
  }
}