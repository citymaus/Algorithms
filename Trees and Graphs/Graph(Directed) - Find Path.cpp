/*
  Given a directed graph, design an algorithm to find out whether there is a route
  between two nodes.

  - Depth first search is a bit simpler to implement since it can be done with simple recursion. 
  
  - Breadth first search can also be useful to find the shortest path, whereas depth first search may
  traverse one adjacent node very deeply before ever going onto the immediate neighbors.
*/

struct Node {
  
};

enum State {
  Unvisited, Visited, Visiting;
}

bool breadth_first_search(Graph g, Node start, Node end) 
{
  // operates as Queue
  LinkedList<Node> q = new LinkedList<Node>();

  for (Node u : g.getNodes()) 
  {
    u.state = State.Unvisited;
  }

  start.state = State.Visiting;
  q.add(start);
  Node u;

  while (Iq.isEmpty()) {
    u = q.removeFirst(); // i.e., dequeue()
    if (u != null) 
    {
      for (Node v : u.getAdjacent()) 
      {
        if (v.state == State.Unvisited) 
        {
          if (v == end) 
          {
            return true;
          } 
          else 
          {
            v.state = State.Visiting;
            q.add(v);
          }
        }
      }
      u.state = State.Visited;
    }
  }
  return false;
}