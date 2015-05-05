/*
  Detect loop in a linked list 
  List could be empty also
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
#include <cstdio>

struct Node
{
    int data;
    struct Node *next;
};

Node* BeginningOfCycle(Node* head)
{
   // Complete this function
   // Do not write the main method
    Node* tortoise = head;
    Node* hare = head;
    while (tortoise && hare && hare->next)
    {
        tortoise = tortoise->next;
        hare = hare->next->next;
        if (tortoise == hare)
        {
            break;
        }
    }

    /* Error check - no meeting point, and therefore no loop */
    if (hare == NULL || hare->next == NULL) {
      return NULL;
    }

    /* Move tortoise to Head. Keep hare at Meeting Point. Each are k
    * steps from the Loop Start. If they move at the same pace,
    * they must meet at Loop Start. */
    tortoise = head;
    while (tortoise != hare) {
      tortoise = tortoise->next;
      hare = hare->next;
    }

    /* Both now point to the start of the loop. */
    return hare;
        
}
