Node* SortedInsert(Node *head,int data)
{
    // Complete this function
   // Do not write the main method. 
    bool added = false;
    Node* curr_node = head;
    Node* prev_node = NULL;
    
    Node* new_node = (Node*)malloc(sizeof(Node*));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    
    /* cout << "adding " << data << " BEFORE:";
    PrintMe(head);
    cout << endl; */
    
    if (head == NULL)
    {
        head = new_node;
        added = true;
    }
    else
    {
        while (curr_node)
        {
            if (data < curr_node->data)
            {
                // Insert before
                if (prev_node != NULL)
                    prev_node->next = new_node;
                else
                    head = new_node;
                curr_node->prev = new_node;
                new_node->prev = prev_node;
                new_node->next = curr_node;
                added = true;
                break;
            }
            prev_node = curr_node;
            curr_node = curr_node->next;
        }
    }
    
    if (!added)
    {
        prev_node->next = new_node;
        new_node->prev = prev_node;
    }
    
    /* cout << "AFTER:";
    PrintMe(head);
    cout << endl;  */
    
    return head;
}