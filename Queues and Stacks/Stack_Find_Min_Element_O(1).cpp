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

stack<int> all;
stack<int> min;

void push(int element)
{
  if (min.empty() || (min.top() > x)
  {
    min.push(x);
  }
  all.push(x);
}

void pop()
{
  if (min.top() == all.top())
  {
    min.pop();
  }
  all.pop();
}