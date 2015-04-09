#include<stdio.h>
#include<stdlib.h>
  
/* Link list node */
struct node
{
    int data;
    struct node* next;
};

node* MergeSort(node *my_node)
{
    node *secondNode;

    if (my_node == NULL)
        return NULL;
    else if (my_node->next == NULL)
        return my_node;
    else
    {
        secondNode = Split(my_node);
        return Merge(MergeSort(my_node),MergeSort(secondNode));
    }
}

node* Merge(node* firstNode, node* secondNode)
{
    if (firstNode == NULL) return secondNode;
    else if (secondNode == NULL) return firstNode;
    else if (firstNode->number <= secondNode->number) //if I reverse the sign to >=, the behavior reverses
    {
        firstNode->next = Merge(firstNode->next, secondNode);
        return firstNode;
    }
    else 
    {
        secondNode->next = Merge(firstNode, secondNode->next);
        return secondNode;
    }
}

node* Split(node* my_node)
{
    node* secondNode;

    if (my_node == NULL) return NULL;
    else if (my_node->next == NULL) return NULL;
    else {
        secondNode = my_node->next;
        my_node->next = secondNode->next;
        secondNode->next = Split(secondNode->next);
        return secondNode;
    }
}

void printList(node* my_node){
    if(my_node == NULL) return;
    else {
        std::cout<<my_node->number<<" "<<std::endl; 
        printList(my_node->next);   
    }
}

printList(myList);
node* sortedList =  MergeSort(myList);
printList(sortedList);  //whole list sorted