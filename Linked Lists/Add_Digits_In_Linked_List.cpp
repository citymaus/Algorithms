
struct Node
{
    int data;
    struct Node *next;
};

/*
  You have two numbers represented by a linked list, where each node contains a
  single digit. The digits are stored in reverse order, such that the 1 's digit is at the head
  of the list. Write a function that adds the two numbers and returns the sum as a
  linked list.

  FOLLOW UP
  Suppose the digits are stored in forward order. Repeat the above problem.

    6 1 7
  + 2 9 5
  -------
    9 1 2
*/

#include <cstdio>

Node *addLists(Node *list1, Node *list2, int carry)
{
  if (list1 == NULL && list2 == NULL && carry == 0)
  {
    return NULL;
  }

  Node *result;
  result->data = 0;
  result->next = NULL;

  int total = carry;
  if (list1 != NULL)
  {
    total += list1->data;
  }
  if (list2 != NULL)
  {
    total += list2->data;
  }
  result->data = total % 10;

  // More to do?
  if (list1 != NULL || list2 != NULL)
  {
    Node *more = addLists((list1 == NULL) ? NULL : list1->next,
                            (list2 == NULL) ? NULL : list2->next,
                            (total >= 10) ? 1 : 0);
    result->next = more;
  }
  return result;
}