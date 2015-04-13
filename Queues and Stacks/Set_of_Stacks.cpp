/* Imagine a (literal) stack of plates. If the stack gets too high, it might topple. Therefore,
in real life, we would likely start a new stack when the previous stack exceeds some
threshold. 
Implement a data structure SetOfStacks that mimics this. SetOf-
Stacks should be composed of several stacks and should create a new stack once
the previous one exceeds capacity. SetOfStacks.push() and SetOfStacks.
pop () should behave identically to a single stack (that is, pop () should return the
same values as it would if there were just a single stack).
*/

#define MAXSTACKSIZE  10

vector<Stack> stacks = new vector<Stack>()j

void init_new_stack()
{
  
}

void push(int value)
{
  Stack last = getLastStackQ;
  if (last != null && !last.isFull()) { // add to last stack
    last.push(v);
  } else { // must create new stack
    Stack stack = new Stack(capacity);
    stack.push(v);
    stacks.add(stack);
  }
}

int pop()
{
  Stack last = getLastStackQ;
  int v = last.popQ;
  if (last.size == 0) 
    stacks.remove(stacks.size() - 1);
  return v;
}
