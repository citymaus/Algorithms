/*
  Insert Node at a given position in a linked list 
  The linked list will not be empty and position will always be valid
  First element in the linked list is at position 0
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

Node* InsertNth(Node *head, int data, int position)
{
  // Complete this method only
  // Do not write main function. 
    //cout << "    insert " << data << " at pos:" << position << endl;
    Node* n = (Node*)malloc(sizeof(Node*));
    n->next = NULL;
    n->data = data;
    /*cout << "BEFORE:";
    PrintMe(head);
    cout << endl; */
    if (head == NULL)
    {
        head = n;    
    }
    else
    {
        Node* curr = head;
        int pos = 0;
        if (position == 0)
        {
            n->next = head;
            head = n;
        }
        while (curr)
        {
            //cout << "currPos:" << pos << endl;
            if (pos == (position-1))
            {
                /*cout << "INSERTING at " << position << " before data:";
                if (curr->next)
                    cout << "(next)" << curr->next->data;
                else
                    cout << curr->data;
                cout << endl; */
                
                n->next = curr->next;
                curr->next = n;
                break;
            }
            pos++;
            curr = curr->next;
        }
    }
    
    return head;
}
