#include <iostream>
#include <string>
using namespace std;

// To execute C++, please define "int main()"
// FACEBOOK PHONE SCREEN, ROUND 1 - 5/22/2015

int main() {
  for (int i = 0; i < 5; i++) {
    cout << "Hello, World\n";
  }
  return 0;
}

string smallest_substring(string input, char alphabet[])
{
  //'ab|bac|ca'
    int numchars = 0;
    map<char, int> used;
    string firstpass = "";
    string smallest = "";
    for (int i = 0; i < input.length(); i++)
    {
        if (used[input[i]] == 0)
        {           
          numchars++;
        }
        used[input[i]]++;
        firstpass += input[i];
        
        if (numchars == sizeof(alphabet)/sizeof(char))
        {
          break;
        }
    }
  
  // firstpass = "abbaac"
    for (int j = 0; j < firstpass.length(); j++)
    {
      if ((used[firstpass[j]] > 1) && (smallest.length() == 0))
      {
          used[firstpass[j]]--;
            //smallest += firstpass[j];          
      }
      else
      {
        smallest += firstpass[j];
      }
    }
      
    return smallest;
}


/* 
Your previous Plain Text content is preserved below:

Given an alphabet of letters and an input string, write a function to find the smallest substring in the input which contains all the letters of the alphabet.

Examples:
alphabet = ['a', 'b', 'c']
input = 'ab|bac|ca'
output = 'bac'

alphabet = ['a', 'b', 'c']
input = 'ab|baac|ca'
output = 'baac'

 */
