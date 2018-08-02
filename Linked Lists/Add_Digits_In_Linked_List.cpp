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
#include "Linked_Lists.h"

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

/*
https://leetcode.com/problems/add-two-numbers/description/
	You are given two non-empty linked lists representing two non-negative integers. 
	The digits are stored in reverse order and each of their nodes contain a single digit. 
	Add the two numbers and return it as a linked list.
	You may assume the two numbers do not contain any leading zero, except the number 0 itself.

	Example:
	Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
	Output: 7 -> 0 -> 8
	Explanation: 342 + 465 = 807.
*/

/*
	Time complexity : O(max(m,n)). 
		Assume that mm and nn represents the length of l1l1 and l2l2 respectively, 
		the algorithm above iterates at most max(m,n) times.

	Space complexity : O(max(m,n)). 
		The length of the new list is at most max(m,n) + 1.
*/
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode head(-1);
	ListNode* answer = &head;
	int carry = 0;
	while (l1 || l2 || carry) {
		int first = (l1 != NULL) ? l1->val : 0;
		int second = (l2 != NULL) ? l2->val : 0;
		int digit = first + second + carry;

		cout << "adding " << first << " + " << second << " + " << carry << " = " << digit;

		if (digit > 9) {
			carry = digit / 10;
			digit = digit % 10;
		}
		else {
			carry = 0;
		}
		cout << " (digit:" << digit << ", carry:" << carry << ")" << endl;

		answer->next = new ListNode(digit);
		answer = answer->next;

		if (l1) {
			l1 = l1->next;
		}
		if (l2) {
			l2 = l2->next;
		}
	}
	return head.next;
}