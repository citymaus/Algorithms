#include <iostream>
using namespace std;

// To execute C++, please define "int main()"
// Facebook Phone Interview Round 2, 6/19/2015

int main() {
  for (int i = 0; i < 5; i++) {
    cout << "Hello, World\n";
  }
  return 0;
}

char *strstr(char *needle, char *haystack)
{
  int haylength = strlen(haystack);
  int needlelength = strlen(needle);
  int num_iterations = haylength - needlelength + 1;
  
  for (int i = 0; i < num_iterations; i++)
  {
    if (!strncmp(needle, &(haystack[i]), needlelength)) return &haystack[i];
  }
  return NULL;
}

// char *strstr(char *needle, char *haystack) // return NULL or ptr