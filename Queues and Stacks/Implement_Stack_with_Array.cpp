/*
  Describe how you could use a single array to implement three stacks.
*/

#include <cstdio>
#include <cstring>

#define STACKSIZE   100
#define NUMSTACKS   3
int buffer[STACKSIZE * NUMSTACKS];
int stackPointer[NUMSTACKS];
int stackSize = 0;

void init()
{
  memset(buffer, 0, sizeof(buffer));
  for (int i = 0; i < NUMSTACKS; i++)
  {
      stackPointer[i] = -1; // pointers to track top element
  }
}

void push(int stackNum, int value)
{
  /* Check if we have space */
  if (stackPointer[stackNum] + 1 >= stackSize) { // Last element
    printf("Out of space.");
  }

  /* Increment stack pointer and then update top value */
  stackPointer[stackNum]++;
  buffer[absTopOfStack(stackNum)] = value;
  stackSize++;
}

int pop(int stackNum)
{
  if (stackPointer[stackNum] == -1) {
    printf("Trying to pop an empty stack.");
  }
  int value = buffer[absTopOfStack(stackNum)]; // Get top
  buffer[absTopOfStack(stackNum)] = -1; // Clear index
  stackPointer[stackNum]--; // Decrement pointer
  stackSize--;
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