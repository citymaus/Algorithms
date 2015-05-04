/*----------------------
  Implement Queue using two Stacks

  Method 1 (by making enqueue costly)
  -----------------------------------
    enQueue(q, x)
    1) While stack1 is not empty, push everything from stack1 to stack2.
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
         While stack1 is not empty, push everything from stack1 to stack2.
    3) Pop the element from stack2 and return it.
------------------------*/

#include <stack>

using namespace std;

class ModifiedQueue {
  private:
    stack<int> s1;
    stack<int> s2;

  public:
    ModifiedQueue() {}

    void enQueue(int x) 
    {
      while (!s1.empty())
      {
        s2.push(s1.top());
        s1.pop();
      }
      s1.push(x);
      while (!s2.empty())
      {
        s1.push(s2.top());
        s2.pop();
      }
    }

    int deQueue()
    {
      if (s1.empty())
      {
        return -1;
      }
      else
      {
        int temp = s1.top();
        s1.pop();
        return temp;
      }
    }
};