#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
struct Node
{
	int data;
	Node *next;
};
Node* Insert(Node *head,int x)
{
   Node *temp = new Node();
   temp->data = x;
   temp->next = NULL;
   if(head == NULL) 
   {
       return temp;
   }
   Node *tail;
   // Get to the end of the list
   for(tail = head;tail->next!=NULL;tail= tail->next);
   tail->next = temp;
   return head;
}
/*
  Delete Node at a given position in a linked list 
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Delete(Node *head, int position)
{
  // Complete this method
    int curr_pos = 0;
    Node *curr = head;
    if (position == 0)
    {
        head = head->next;    
    }
    while (curr != NULL)
    {
        if ((curr_pos+1) == position)
        {
            curr->next = curr->next->next;
        }
        curr_pos++;
        curr = curr->next;
    }
    return head;
}

void Print(Node* head)
{
	while(head != NULL)
	{
		cout<<head->data;
		head=head->next;
	}
}

int main()
{
	int t;
	cin>>t;
	while(t-- >0){
		int x; cin>>x;
		 Node *head = NULL;
                while(x--)
                {
                   int y;cin>>y;
		           head = Insert(head,y);
                }
       int pos;cin>>pos;
	   head = Delete(head,pos);
	   Print(head);
	   cout<<"\n";
	}

}