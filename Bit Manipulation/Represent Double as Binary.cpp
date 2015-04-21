/*
  Given a real number between 0 and 1 (e.g., 0.72) that is passed in as a double, print
  the binary representation. If the number cannot be represented accurately in binary
  with at most 32 characters, print "ERROR."

  First, let's start off by asking ourselves what a non-integer number in binary looks like. By
  analogy to a decimal number, the binary number 0.101v2 would look like:
  0.101v2 = 1 * (1/2^1) + 0 * (1/2^2) + 1 * (1/2^3).

  To print the decimal part, we can multiply by 2 and check if 2n is greater than or equal
  to 1.This is essentially "shifting" the fractional sum. That is:
  (v = subscript, ^ = superscript)
  r = 2v10 * n
  = 2v10 * 1.101v2
  = 1 * (1/2^0) + 0 * (1/2^1) + 1 * (1/2^2)
  = 1.01v2

  If r >= 1, then we know that n had a 1 right after the decimal point. By doing this
  continuously, we can check every digit.
*/

static string printBinary(double num) 
{
  if (num >= 1 || num <= 0) {
    return "ERROR";
  }

  string binary = "";
  binary += ".";
  while (num > 0) 
  {
    /* Setting a limit on length: 32 characters */
    if (strlen(binary) >= 32) 
    {
      return "ERROR";
    }

    double r = num * 2;
    if (r >= 1) {
      binary += "1";
      num = r - 1;
    } else {
      binary += "0";
      num = r;
    }
  }
  return binary;
}