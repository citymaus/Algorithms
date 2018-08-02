/*
	Floyd's Algorithm to detect a cycle
	http://en.wikipedia.org/wiki/Cycle_detection#Tortoise_and_hare
	
		*Singly linked list
*/
#include "Trees_and_Graphs.h"

int Floyds_Has_Cycle(Node* head)
{
   // Complete this function
   // Do not write the main method
    Node* tortoise = head;
    Node* hare = head;
    if (head != NULL)
    {
        while (tortoise && hare && hare->next)
        {
            tortoise = tortoise->next;
            hare = hare->next->next;
            if (tortoise == hare)
            {
                return 1;    
            }
        }
    }        
    return 0;
}