/*----------------------
  Find min element in stack in O(1) time, 
  with O(n) space complexity

  1. Maintain two stacks.
  2. Before each push on stack 1, check to see if it is less than top of stack 2
  3. If so, push to stack 2
  4. When popping, check if stack 2's top equals popped value
  5. If so, pop stack 2

  Min is always top of stack 2.
------------------------*/
#include<stack>
using namespace std;

stack<int> allstack;
stack<int> minstack;

void push(int element)
{
  if (minstack.empty() || (minstack.top() > element))
  {
    minstack.push(element);
  }
  allstack.push(element);
}

void pop()
{
  if (minstack.top() == allstack.top())
  {
    minstack.pop();
  }
  allstack.pop();
}

int get_min()
{
	return minstack.top();
}