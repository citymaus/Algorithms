/*----------------------

  Check if one string is permutation of another string
  
  You have two strings and you need to decide if the first one is a permutation of the other one. 
  The solution uses HashMap data structure where each symbol of the first string is stored as a 
  key and its value is the number of times this symbol appears. 

  Then you loop through the second string and for each character which is a key in the HashMap you 
  decrease the number of times this character appeared in the first string. 
  In the end if the two strings are permutations of each other, you will end up with a HashMap with all values 0:

------------------------*/
using System.Collections.Generic;

namespace Permutations
{
  public static class TheClass
  {
    bool arePermutations(string str1, string str2) 
    {
        if (str1.length() != str2.length()) 
        {
            return false;
        }
        Dictionary<char, int> hashMapChars = new Dictionary<char, int>();

        // enter the chars and the number of times each of them appears
        for (int i = 0; i < str1.length(); i++) 
        {
            if (sthashMapChars.ContainsKey(str1[i])) 
            {
                hashMapChars[str[i]] += 1;
            } 
            else 
            {
                hashMapChars.add(str1[i], 1);   
            }
        }
        // for each char in str2 decrease the value number
        for (int i = 0; i < str2.length(); i++) 
        {
          if (hashMapChars.ContainsKey(str2[i])) 
          {
            int count = hashMapChars[str2[i]];
            count--;
            if (count < 0) 
            {
                  return false;
            }
            hashMapChars[str2[i]] = count;
          } 
		      else 
		      {
            return false;
          }
        }
        return true;
    }
  }
}