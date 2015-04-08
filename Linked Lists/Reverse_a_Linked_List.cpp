/*
  Reverse a linked list and return pointer to the head
  The input list will have at least one element  
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

Node* Reverse(Node *head)
{
  // Complete this method
    Node* prev_node = NULL;
    Node* next_node = head->next;
    
    /*cout << "BEFORE:";
    PrintMe(head);
    cout << endl; */
    
    while (head)
    {
        next_node = head->next;
        head->next = prev_node;
		    prev_node = head;
		    head = next_node;
    }
    
    /*cout << "AFTER:";
    PrintMe(curr_node);
    cout << endl; */
    
    return prev_node;
}
