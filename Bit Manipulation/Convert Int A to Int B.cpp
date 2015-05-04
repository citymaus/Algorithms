/*
  Write a function to determine the number of bits required to convert integer A to
  integer B.

  A = 1011 0111
  B = 0111 1010
  c = 1100 1101 = 5 bits after XOR
*/

int bitSwapRequired(int a, int b) 
{
  int count = 0;
  for (int c = a ^ b; c != 0; c = c >> 1) 
  {
    // XOR for differing bits
    count += c & 1;
  }
  return count;
}