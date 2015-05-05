  
#include <cstdio>
#include <stack>
using namespace std;

struct Node
  {
     int data;
     struct Node *next;
  };

  /*
    Implement a function to check if a linked list is a palindrome.
  */
  bool isPalindrome(Node *head)
  {
    Node *fast = head;
    Node *slow = head;
    
    stack<int> stack1;
    
    /* Push elements from first half of linked list onto stack. When
    * fast runner (which is moving at 2x speed) reaches the end of
    * the linked list, then we know we're at the middle */
    while (fast != NULL && fast->next != NULL) {
      stack1.push(slow->data);
      slow = slow->next;
      fast = fast->next->next;
    }
    
    /* Has odd number of elements, so skip the middle element */
    if (fast != NULL) {
      slow = slow->next;
    }
    
    while (slow != NULL) {
      int top = stack1.top();
      stack1.pop();
    
      /* If values are different, then it's not a palindrome */
      if (top != slow->data) {
        return false;
      }

      slow = slow->next;
    }

    return true;
  }