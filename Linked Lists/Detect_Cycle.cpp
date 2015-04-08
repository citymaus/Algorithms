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

int HasCycle(Node* head)
{
   // Complete this function
   // Do not write the main method
    Node* tortoise = head;
    Node* hare = head;
    if (head != NULL)
    {
        while (tortoise && hare && hare->next)
        {
            tortoise = tortoise->next;
            hare = hare->next->next;
            if (tortoise == hare)
            {
                return 1;    
            }
        }
    }
        
    return 0;
}
