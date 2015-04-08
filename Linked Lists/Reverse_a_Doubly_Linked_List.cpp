#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
struct Node
{
	int data;
	Node* next;
	Node* prev;
};
/*
   Reverse a doubly linked list, input list may also be empty
   Node is defined as
   struct Node
   {
     int data;
     Node *next;
     Node *prev;
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

Node* Reverse(Node* head)
{
    /*cout << "BEFORE:";
    PrintMe(head);
    cout << endl; */
    
    // Complete this function
    // Do not write the main method. 
    Node* curr_node = head;
    while (curr_node != NULL)
    {
        Node* temp = curr_node->next;
        curr_node->next = curr_node->prev;
        curr_node->prev = temp;
        head = curr_node;
        curr_node = temp;
    }
    /* cout << "AFTER:";
    PrintMe(head);
    cout << endl; */
    return head;
}

Node* Insert(Node *head, int data)
{
	Node *temp = new Node();
	temp->data = data; temp->prev = NULL; temp->next = NULL;
	if(head == NULL) return temp;
	head->prev = temp;
	temp->next = head;
	return temp;
}
void Print(Node *head) {
	if(head == NULL) return;
	while(head->next != NULL){ cout<<head->data<<" "; head = head->next;}
	cout<<head->data<<" ";
	while(head->prev != NULL) { cout<<head->data<<" "; head = head->prev; }
	cout<<head->data<<"\n";
}
int main()
{
	int t; cin>>t;
	Node *head = NULL;
	while(t--) {
	   int n; cin>>n;
           head = NULL;
	   for(int i = 0;i<n;i++) {
		   int x; cin>>x;
		   head = Insert(head,x);
	   }
	   head = Reverse(head);
	   Print(head);
	}
}