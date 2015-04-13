/*
  Describe how you could use a single array to implement three stacks.
*/

#define STACKSIZE   100
#define NUMSTACKS   3
int buffer[STACKSIZE * NUMSTACKS];
int stackPointer[NUMSTACKS];

void init()
{
  memset(buffer, 0, sizeof(buffer));
  stackPointer = {-1, -1, -1}; // pointers to track top element
}

void push(int stackNum, int value)
{
  /* Check if we have space */
  if (stackPointer[stackNum] + 1 >= stackSize) { // Last element
    throw new Exception("0ut of space.");
  }

  /* Increment stack pointer and then update top value */
  stackPointer[stackNum]++;
  buffer[absTopOfStack(stackNum)] = value;
}

int pop()
{
  if (stackPointer[stackNum] == -1) {
    throw new Exception("Trying to pop an empty stack.");
  }
  int value = buffer[absTopOfStack(stackNum)]; // Get top
  buffer[absTopOfStack(stackNum)] = 0; // Clear index
  stackPointer[stackNum]--; // Decrement pointer
  return value;
}

int peek(int stackNum)
{
  return buffer[absTopOfStack(stackNum)];
}

bool isEmpty(int stackNum)
{
  return stackPointer[stackNum] == -1;
}

int absTopOfStack(int stackNum) 
{
  return stackNum * STACKSIZE + stackPointer[stackNum];
}