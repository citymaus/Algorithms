/*
  Compare two linked lists A and B
  Return 1 if they are identical and 0 if they are not. 
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
int CompareLists(Node *headA, Node* headB)
{
  // This is a "method-only" submission. 
  // You only need to complete this method 
    Node *currA = headA;
    Node *currB = headB;
    while (currA != NULL)
    {
        if (currA->data != currB->data)
        {
            //cout << "a:" << currA->data << " b:" << currB->data << endl;
            return 0;
        }
        currA = currA->next;
        currB = currB->next;
    }
    if (currB != NULL)
    {
        return 0;    
    }
    
    return 1;
}
