/* Imagine a (literal) stack of plates. If the stack gets too high, it might topple. Therefore,
in real life, we would likely start a new stack when the previous stack exceeds some
threshold. 
Implement a data structure SetOfStacks that mimics this. SetOf-
Stacks should be composed of several stacks and should create a new stack once
the previous one exceeds capacity. SetOfStacks.push() and SetOfStacks.
pop () should behave identically to a single stack (that is, pop () should return the
same values as it would if there were just a single stack).
*/

#include <cstdio>
#include <vector>
#include <stack>
#include <deque>

using namespace std;

#define MAXSTACKSIZE  10

vector<stack<int>> stacks;

void init_new_stack()
{
  
}

void push(int value)
{
  stack<int> last = stacks.back();
  if (last.top() != NULL && !isFull(last)) { // add to last stack
    last.push(value);
  } else { // must create new stack
    deque<int> temp (MAXSTACKSIZE, 0);
    stack<int> stack1 (temp);
    stack1.push(value);
    stacks.push_back(stack1);
  }
}

int pop()
{
  stack<int> last = stacks.back();
  int v = last.top();
  last.pop();
  if (last.size() == 0) 
    stacks.pop_back();
  return v;
}

bool isFull(stack<int> s)
{
  if (s.size() == MAXSTACKSIZE)
    return true;

  return false;
}
