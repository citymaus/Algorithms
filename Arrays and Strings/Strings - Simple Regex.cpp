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

/*
Simple regex matcher

bool is_match(char *regex, char *s);

. - wildcard
* - 0 or more repetitions of previous character

R S

abc abc true
.bc xbc true
.bc bc false

a*b b
    ab
    aaaaaab (all true)
    
.*
abc abcd false

.*.*
efnoweinfosdnflksd

a*ab aaaab

*/

// abc abc
// .*.*
bool is_match(char *regex, char *s)
{
  bool foundmatch = false;
  int sindex = 0;
  
  // return false;
  if ((strlen(regex) == 0 && strlen(s) != 0)
      || (strlen(regex) != 0 && strlen(s) == 0))
  {
    return false;
  }
  if (strlen(regex) == 0 && strlen(s) == 0)
  {
    // base case
    return true;
  }
  else if (regex[0] == '.' && regex[1] == '*')
  {
    return is_match(regex, s++) || is_match(regex+2, s);
  }
  else if (regex[0] == '.')
  {
    return is_match(regex++, s++);
  }
  else if (regex[0] == '*')
  {
    return is_match(regex, s++);
    
  }
  
    
  if (regex[0] == s[0])
  {
    return is_match(regex, s++);
  }
  else {
    return is_match(regex++, s));
  }
  
  return is_match(regex++, s++);
 
  /*
  for (int i = 0; i < strlen(regex); i++)
  {
    if (regex[i] == '.' && regex[i+1] == '*')
    {
      char nextstrict = regex[i+2]
    }
    else (regex[i] == '.')
    {
      sindex++;
    }
    else (regex[i] == '*')
    {
      if (s[sindex] != regex[i-1])
      {
        return false;
      }
    }
    else
    {
      if (s[sindex] == regex[i])
      {
        sindex++;        
      }
      else
      {
        return false;
      }
    }
  }*/
}



