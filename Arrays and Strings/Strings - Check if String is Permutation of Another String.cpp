/*----------------------

  Check if one string is permutation of another string
  
  You have two strings and you need to decide if the first one is a permutation of the other one. 
  The solution uses HashMap data structure where each symbol of the first string is stored as a 
  key and its value is the number of times this symbol appears. 

  Then you loop through the second string and for each character which is a key in the HashMap you 
  decrease the number of times this character appeared in the first string. 
  In the end if the two strings are permutations of each other, you will end up with a HashMap with all values 0:

------------------------*/
#include <cstdio>
#include <string>
#include <map>
using namespace std;

bool arePermutations(string str1, string str2) 
{
    if (str1.length() != str2.length()) 
	{
        return false;
    }
    map<char, int> hashMapChars;

    // enter the chars and the number of times each of them appears
    for (int i = 0; i < str1.length(); i++) 
	{
		map<char, int>::iterator it = hashMapChars.find(str1[i]);
        if (it != hashMapChars.end()) 
		{
            it->second += 1;
        } 
		else 
		{
            hashMapChars.insert(make_pair(str1[i], 1));   
		}
    }
    // for each char in str2 decrease the value number
    for (int i = 0; i < str2.length(); i++) 
	{
		map<char, int>::iterator it = hashMapChars.find(str2[i]);
        if (it != hashMapChars.end()) 
		{
			int count = it->second;
            count--;
            if (count < 0) 
			{
                return false;
            }
            it->second = count;
        } 
		else 
		{
                return false;
        }
    }
    return true;
}