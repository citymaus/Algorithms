/*
  Write a function to determine the number of bits required to convert integer A to
  integer B.
*/

int bitSwapRequired(int a, int b) 
{
  int count = 0;
  for (int c = a ^ b; c != 0; c = c » 1) 
  {
    // XOR for differing bits
    count += c & 1;
  }
  return count;
}