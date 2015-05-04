/*
In the classic problem of the Towers of Hanoi, you have 3 towers and N disks of
different sizes which can slide onto any tower. The puzzle starts with disks sorted
in ascending order of size from top to bottom (i.e., each disk sits on top of an even
larger one). You have the following constraints:
(1) Only one disk can be moved at a time.
(2) A disk is slid off the top of one tower onto the next rod.
(3) A disk can only be placed on top of a larger disk.
Write a program to move the disks from the first tower to the last using Stacks.
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
using namespace std;

void main(string args[]) {
  int n = 3;
  Tower towers[3];
  for (int i = 0; i < 3; i++) {
      towers[i].setI(i);
  }
  for (int i = n - 1; i >= 0; i--) {
    towers[0].add(i);
  }
  towers[0].moveDisks(n, towers[2], towers[1]);
}

class Tower {
private:
    stack<int> disks;
    int ind;
  
public:
    Tower()
    {
    }

    void setI(int i)
    {
        ind = i;
    }

    int index() 
    {
        return ind;
    }

    void add(int d) 
    {
        if (!disks.empty() && disks.top() <= d) 
        {
            cout << "Error placing disk " << d;
        } 
        else 
        {
            disks.push(d);
        }
    }

    void moveTopTo(Tower t) 
    {
        int top = disks.top();
        disks.pop();
        t.add(top);
        cout << "Move disk " << top << " from " << index() << " to " << t.index();
    }

    void moveDisks(int n, Tower destination, Tower buffer) 
    {
        if (n > 0) 
        {
          moveDisks(n - 1, buffer, destination);
          moveTopTo(destination);
          moveDisks(n - 1, destination, buffer);
        }
    }
};