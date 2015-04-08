void ReversePrint(Node *head)
{
  // This is a "method-only" submission. 
  // You only need to complete this method. 
    
    Node* prev_node = NULL;
    Node* next_node = NULL;
    
    /* cout << "BEFORE:";
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
    
    PrintMe(prev_node);
}