/*----------------------
  Reverse a string
------------------------*/
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

void reverseString()
{
  string original, reverse = "";
 
  cout << "Enter a string to reverse" << endl;
  getline(cin, original);
 
  int length = original.length();
 
  for (int i = length - 1; i >= 0 ; i--)
      reverse = reverse + original[i];
 
  cout << "Reverse of entered string is: " << reverse;
}

void strrev(char *beg)
{
  char *end = beg;
  while(end && *end) ++end;
  for(--end; beg < end; ++beg, --end)
    *beg = *beg ^ *end,
    *end = *beg ^ *end,
    *beg = *beg ^ *end;
}

/* PRE: str must be either NULL or a pointer to a 
 * (possibly empty) null-terminated string. */
void strrev(char *str) 
{
  char temp, *end_ptr;

  /* If str is NULL or empty, do nothing */
  if( str == NULL || !(*str) )
    return;

  end_ptr = str + strlen(str) - 1;

  /* Swap the chars */
  while( end_ptr > str ) {
    temp = *str;
    *str = *end_ptr;
    *end_ptr = temp;
    str++;
    end_ptr--;
  }
}