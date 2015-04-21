/*
  Given a positive integer, print the next smallest and the next largest number that
  have the same number of 7 bits in their binary representation.

  If we think about what the next number should be, we can observe the following. Given
  the number 13948, the binary representation looks like:
  (num1s = 9, num0s = 5)
                  P
  1  1  0  1  1 0 0 1 1 1 1 1 0 0
  13 12 11 10 9 8 7 6 5 4 3 2 1 0

  We want to make this number bigger (but not too big). We also need to keep the same
  number of ones.

  [LARGER NUMBER FIRST]
  We want to make the number bigger, but not unnecessarily bigger. Therefore, we
  need to: 
  1. Flip the rightmost non-trailing zero which has ones on the right of it.
  (bit 7 = p)
  (num1sRightofP (c1) = 5, num0sRightofP (c0) = 2)
                  P
  1  1  0  1  1 0 1 1 1 1 1 1 0 0
  13 12 11 10 9 8 7 6 5 4 3 2 1 0

  2. Clear bits right of P.
                  P
  1  1  0  1  1 0 1 0 0 0 0 0 0 0
  13 12 11 10 9 8 7 6 5 4 3 2 1 0

  3. Add in c1 - 1, ones at the right.
                  P  
  1  1  0  1  1 0 1 0 0 0 1 1 1 1
  13 12 11 10 9 8 7 6 5 4 3 2 1 0

*/

int getNext(int n) 
{
  /* Compute c0 and cl */
  int c = n;
  int c0 = 0;
  int cl = 0;
  while (((c & 1) == 0) && (c != 0)) 
  {
    c0++;
    c = c >> 1;
  }
  
  while ((c & 1) == 1) 
  {
    c1++;
    c = c >> 1;
  }

  /* Error: if n == 11..1100...00, then there is no bigger number 
  * with the same number of Is. */
  if (c0 + cl == 31 || c0 + c1 == 0) 
  {
    return -1;
  }

  int p = c0 + c1;          // position of rightmost non-trailing zero
  n |= (1 << p);            // Flip rightmost non-trailing zero

  int a = 0;
  int b = 0;
  int mask = 0;

  //n &= ~((1 << p) - 1);     // Clear all bits to the right of p (concise)
  a = 1 << p;   // all zeros except for a 1 at position p.
  b = a - 1;    // all zeros, followed by p ones,
  mask = ~b;    // all ones, followed by p zeros,
  n = n & mask; // clears rightmost p bits.

  //n |= (1 << (c1 - 1)) - 1; // Insert (c1-1) ones on the right. (concise)
  a = 1 << (c1 - 1);  // 0s with a 1 at position c1 - 1, num ones needed to match
  b = a - 1;          // replace 0s with 1s at positions 0 through c1 - 1
  n = n | b;          // inserts 1s at positions 0 through c1 - 1

  return n;
}

/*
    (bit 7 = p)
  (num1sRightofP (c1) = 2, num0sRightofP (c0) = 5)
                  P
  1  0  0  1  1 1 1 0 0 0 0 0 1 1
  13 12 11 10 9 8 7 6 5 4 3 2 1 0

  1. Flip the rightmost, non-trailing 1 to 0.
                  P
  1  0  0  1  1 1 0 0 0 0 0 0 1 1
  13 12 11 10 9 8 7 6 5 4 3 2 1 0

  2. Clear all bits to the right of p.
                  P
  1  0  0  1  1 1 0 0 0 0 0 0 0 0
  13 12 11 10 9 8 7 6 5 4 3 2 1 0

  3. Insert c1 + 1 ones immediately to the right of position p.
                  P  
  1  0  0  1  1 1 0 1 1 1 0 0 0 0
  13 12 11 10 9 8 7 6 5 4 3 2 1 0


*/

int getPrev(int n) 
{
  int temp = n;
  int c0 = 0;
  int cl = 0;
  while (temp & 1 == 1) 
  {
    c1++;
    temp = temp >> 1;
  }

  if (temp == 0) return -1;

  while (((temp & 1) == 0) && (temp != 0)) 
  {
    c0++;
    temp = temp >> 1;
  }

  int p = c0 + c1; // position of rightmost non-trailing one
  
  //n &= << (p + 1);      // clears from bit p onwards (concise)
  int a = ~0;             // Sequence of 1s
  int b = a << (p + 1);   // Sequence of 1s followed by p + 1 zeros.
  n &= b;                 // Clears bits 0 through p.

  //int mask = (1 << (c1 + 1)) - 1); // Sequence of (c1 + 1) ones
  //n |= mask << (c0 - 1);
  int a = 1 << (c1 + 1);   // 0s with 1 at position (cl + 1)
  int b = a - 1;           // 0s followed by cl + 1 ones
  int c = b << (c0 - 1);   // c1+1 ones followed by c0-1 zeros,
  n |= c;

  return n;
}