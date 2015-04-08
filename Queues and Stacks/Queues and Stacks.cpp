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

stack<int> all;
stack<int> min;

void push(int element)
{
  if (min.isEmpty() || (min.peek() > x)
  {
    min.push(x);
  }
  all.push(x);
}

void pop()
{
  if (min.peek() == all.peek())
  {
    min.pop();
  }
  all.pop();
}


/*----------------------
  Implement Queue using two Stacks

  Method 1 (by making enqueue costly)
  -----------------------------------
    enQueue(q, x)
    1) While stack1 is not empty, push everything from satck1 to stack2.
    2) Push x to stack1 (assuming size of stacks is unlimited).
    3) Push everything back to stack1.

    deQueue(q)
    1) If stack1 is empty then error
    2) Pop an item from stack1 and return it

  Method 2 (by making dequeue costly)
  ----------------------------------
    enQueue(q,  x)
    1) Push x to stack1 (assuming size of stacks is unlimited).

    deQueue(q)
    1) If both stacks are empty then error.
    2) If stack2 is empty
         While stack1 is not empty, push everything from satck1 to stack2.
    3) Pop the element from stack2 and return it.
------------------------*/
