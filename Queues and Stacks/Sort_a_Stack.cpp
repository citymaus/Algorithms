/*
Write a program to sort a stack in ascending order (with biggest items on top).
You may use at most one additional stack to hold items, but you may not copy the
elements into any other data structure (such as an array). The stack supports the
following operations: push, pop, peek, and isEmpty.

STEP 0    STEP 1    STEP 2    STEP 3
s   r     s   r     s   r     s   r
------    ------    ------    ------
    12        12    8         8   
5   8         8     12        12  5
10  3     10  3     10  3     10  3
7   1     7   1     7   1     7   1
-----     -----     ------    ------
          tmp = 5   tmp = 5   tmp = --

*/

#include <cstdio>
#include <stack>
using namespace std;

stack<int> sort(stack<int> s) 
{
  stack<int> r;
  while (!s.empty()) 
  {
    int tmp = s.top(); // Step 1
    s.pop();
    while (!r.empty() && r.top() > tmp) 
    { // Step 2
      s.push(r.top());
      r.pop();
    }
    r.push(tmp); // Step 3
  }
  return r;
}