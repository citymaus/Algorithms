/*
  Given a positive integer, print the next smallest and the next largest number that
  have the same number of 7 bits in their binary representation.

  If we think about what the next number should be, we can observe the following. Given
  the number 13948, the binary representation looks like:
  (num1s = 9, num0s = 5)
  1  1  0  1  1 0 0 1 1 1 1 1 0 0
  13 12 11 10 9 8 7 6 5 4 3 2 1 0

  We want to make this number bigger (but not too big). We also need to keep the same
  number of ones.

  [LARGER NUMBER FIRST]
  We want to make the number bigger, but not unnecessarily bigger. Therefore, we
  need to flip the rightmost non-trailing zero which has ones on the right of it.
  (bit 7 = p)
  (num1sRightofP = 5, num0sRightofP = 2)
                  P
  1  1  0  1  1 0 1 1 1 1 1 1 0 0
  13 12 11 10 9 8 7 6 5 4 3 2 1 0

  Clear bits right of P.
                  P
  1  1  0  1  1 0 1 0 0 0 0 0 0 0
  13 12 11 10 9 8 7 6 5 4 3 2 1 0

  Add in num1stRightofP - 1, ones.
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
  n &= ~((1 << p) - 1);     // Clear all bits to the right of p
  n |= (1 << (c1 - 1)) - 1; // Insert (cl-1) ones on the right.

  return n;
}

int getPrev(int n) 
{
  int temp = n;
  int C0 = 0;
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
  n &= << (p + 1);  // clears from bit p onwards

  int mask = (1 << (c1 + 1)) - 1); // Sequence of (c1 + 1) ones
  n |= mask << (c0 - 1);

  return n;
}