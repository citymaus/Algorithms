/*
  Write methods to implement the multiply, subtract, and divide operations for integers.
  Use only the add operator.
*/

/* Flip a positive sign to negative or negative sign to positive */
int negate(int a) 
{
  int neg = 0;
  int d = a < 0 ? 1 : -1;
  while (a != 0) 
  {
    neg += d;
    a += d;
  }
  return neg;
}

/* Subtract two numbers by negating b and adding them */
int minus(int a, int b) 
{
  return a + negate(b);
}

/* Multiply a by b by adding a to itself b times */
int multiply(int a, int b) 
{
  if (a < b) 
  {
    return multiply(b, a); // algorithm is faster if b < a
  }
  int sum = 0;
  for (int i = abs(b); i > 0; i--) 
  {
    sum += a;
  }
  if (b < 0) 
  {
    sum = negate(sum);
  }
  return sum;
}

/* Return absolute value */
int abs(int a)
{
  if (a < 0)
  {
    return negate(a);
  } 
  else
  {
    return a;
  }
}

int divide(int a, int b)
{
  if (b == 0) 
  {
    // ERROR, can't divide by 0
    return -1;
  }
  int absa = abs(a);
  int absb = abs(b);


  /*
    x = a / b
    a = bx
  */
  int product = 0;
  int x = 0;
  while (product + absb <= absa) 
  { /* don't go past a */
    product += absb;
    x++;
  }

  // If one int is negative, return a negative result.
  if ((a < 0 && b < 0) || (a > 0 && b > 0)) 
  {
    return x;
  } 
  else 
  {
    return negate(x);
  }
}

int divide2(int a, int b)
{
    int tmp = a, quotient = 0;
    while (tmp >= b) {
        tmp = tmp - b;
        quotient++;
    }

    printf ("Result %d, Remainder %d\n", quotient, tmp);
    return quotient;
}