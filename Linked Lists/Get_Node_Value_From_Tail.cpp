/*
  Get Nth element from the end in a linked list of integers
  Number of elements in the list will always be greater than N.
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
int GetNode(Node *head,int positionFromTail)
{
  // This is a "method-only" submission. 
  // You only need to complete this method. 
    Node* curr = head;
    int list_size = 1;
    int node_idx = 0;
    while (curr->next != NULL)
    {
        curr = curr->next;
        list_size++;
    }
    //cout << "size: " << list_size << endl;
    curr = head;
    
    while (curr->next != NULL)
    {
        if (node_idx == (list_size - 1 - positionFromTail))
        {
            return curr->data;    
        }
        else
        {
            curr = curr->next;
            node_idx++;
        }
    }
    return curr->data;
}
