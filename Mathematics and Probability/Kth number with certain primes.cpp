/*
  Design an algorithm to find the kth number such that the only prime factors are 3,
  5, and 7.

  We know that, by definition, any such number will look like 3a * 5b * 7c.
  Let's picture a list of all numbers in that form. This problem asks us to find the kth such
  number.
                3^a * 5^b * 7^c
                ---------------
  1     -       3^0 * 5^0 * 7^0
  3     3       3^1 * 5^0 * 7^0
  5     5       3^0 * 5^1 * 7^0
  7     7       3^0 * 5^0 * 7^1
  9     3*3     3^2 * 5^0 * 7^0
  15    3*5     3^1 * 5^1 * 7^0
  21    3*7     3^1 * 5^0 * 7^1
  25    5*5     3^0 * 5^2 * 7^0
  27    3*3*3   3^3 * 5^0 * 7^0
  35    5*7     3^0 * 5^1 * 7^1
  45    5*3*3   3^2 * 5^1 * 7^0
  49    7*7     3^0 * 5^0 * 7^2
  63    7*3*3   3^2 * 5^0 * 7^1

*/

#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

int getKthMagicNumber(int k) {
  if (k < 0) 
  {
    return 0;
  }
  int val = 0;
  queue<int> queue3;
  queue<int> queue5;
  queue<int> queue7;
  queue3.push(1);

  /* Include 0th through kth iteration */
  for (int i = 0; i <= k; i++) 
  {
    int v3 = queue3.size() > 0 ? queue3.front() :  INT_MAX;
    int v5 = queue5.size() > 0 ? queue5.front() :  INT_MAX;
    int v7 = queue7.size() > 0 ? queue7.front() :  INT_MAX;
    val = min(v3, min(v5, v7));
    if (val == v3) 
    { // enqueue into queue 3, 5 and 7
      queue3.pop();
      queue3.push(3 * val);
      queue5.push(5 * val);
    } 
    else if (val == v5) 
    { // enqueue into queue 5 and 7
      queue5.pop();
      queue5.push(5 * val);
    } 
    else if (val == v7) 
    { // enqueue into Q7
      queue7.pop();
    }
    queue7.push(7 * val); // Always enqueue into Q7
  }
  return val;
}