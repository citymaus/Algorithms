/*
  Merge two sorted lists A and B as one linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/

void PrintMe(Node* head);
void PrintMe(Node* head)
{
	while(head != NULL)
	{
		cout<<head->data;
		head=head->next;
	}
}

Node* MergeLists(Node *headA, Node* headB)
{
    //cout << "  LIST A:"; PrintMe(headA); cout << endl;
    //cout << "  LIST B:"; PrintMe(headB); cout << endl;
  // This is a "method-only" submission. 
  // You only need to complete this method 
    Node* head = NULL;
    Node* next_node = NULL;
    
    if (headA == NULL)
        return headB;
    if (headB == NULL)
        return headA;
        
    while (headA && headB)
    {
        // Set up return head
        if (head == NULL)
            if (headA->data < headB->data)
                head = headA;
            else
                head = headB;
        
        //cout << "A:" << headA->data << " B:" << headB->data << endl;
  
        if (headA->data < headB->data)
        {
            next_node = headA->next;
            // Is A's next smaller than B?
            if ((headA->next != NULL) && (headA->next->data < headB->data))
            {
                //cout << headA->data << " is pointing to " << headA->next->data << endl;
                // No change
                headA = headA->next;
            }
            else // B is smaller than A's next
            {
                //cout << headA->data << " is pointing to " << headB->data << endl;
                headA->next = headB;
            }
            headA = next_node;
        }
        else // B's smaller than A
        {
            next_node = headB->next;
            // Is B's next smaller than A?
            if ((headB->next != NULL) && (headB->next->data < headA->data))
            {
                // No change
                headB = headB->next;
                //cout << headB->data << " is pointing to " << headB->next->data << endl;
            }
            else // A is smaller than B's next
            {
                //cout << headB->data << " is pointing to " << headA->data << endl;
                headB->next = headA;
            }
            headB = next_node;            
        }
            
    }
    return head;
}
