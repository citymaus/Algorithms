#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

/*----------------------
  Determine if a string has all unique characters

  implement an algorithm to determine if a string has all unique characters. 
  What if you cant use additional data structures.
------------------------*/

//solution1: use set as additional data structure. 
//  insert each character in the string to the set. if the string has all  unique characters, 
//  the size of the set should be equal to the size of string.
bool hasUniqueChars(char *s)
{
    if (!s) 
        throw("empty input");
    set<char> myset;
    int i;
    for(i=0; s[i]!='\0'; i++){
        myset.insert(s[i]);
    }
    if (myset.size() == i)
        return true;
    else
        return false;
}

//solution2: if dont use extra data structure, for each char, search following chars, 
// time complexity = O(n^2)
bool bfhasUniqueChars(char *s)
{
    if (!s) 
        throw("empty input\n");
    int len = strlen(s);
    for (int i=0; i < len; i++) {
        char tmp = s[i];
        for (int j=i+1; j<len; j++)
            if (s[j] == tmp)
                return false;
    }
    return true;
}

//solution3: quicksort first, then check if next element equals current element.
boolean checkUnique(char arr[])
{
    quicksort(arr);   // O(n*lg(n))
    for(int i = 0; i < arr.length - 1; ++i)
        if(arr[i] == arr[i + 1])
            return false;
 
    return true;
}


/*----------------------
  Reverse a string
------------------------*/

void reverseString()
{
  string original, reverse = "";
 
  cout << "Enter a string to reverse" << endl;
  getline(cin, original);
 
  int length = strlen(original);
 
  for (int i = length - 1; i >= 0 ; i--)
      reverse = reverse + original[i];
 
  cout << "Reverse of entered string is: " << reverse;
}

/*----------------------

  Check if one string is permutation of another string
  
  You have two strings and you need to decide if the first one is a permutation of the other one. 
  The solution uses HashMap data structure where each symbol of the first string is stored as a 
  key and its value is the number of times this symbol appears. 

  Then you loop through the second string and for each character which is a key in the HashMap you 
  decrease the number of times this character appeared in the first string. 
  In the end if the two strings are permutations of each other, you will end up with a HashMap with all values 0:

------------------------*/

boolean arePermutations(string str1, string str2) 
{
    if (strlen(str1) != strlen(str2)) {
        return false;
    }
    HashMap hashMapChars = new HashMap();

    // enter the chars and the number of times each of them appears
    for (int i = 0; i < str1.length(); i++) {
        if (hashMapChars.containsKey(str1.charAt(i))) {
            int count = hashMapChars.get(str1.charAt(i));
            hashMapChars.put(str1.charAt(i), count + 1);
        } else {
            hashMapChars.put(str1.charAt(i), 1);   }
        }
    }
    // for each char in str2 decrease the value number
    for (int i = 0; i < str2.length(); i++) {
        if (hashMapChars.containsKey(str2.charAt(i))) {
            int count = hashMapChars.get(str2.charAt(i));
            count--;
            if (count < 0) {
                return false;
            }
            hashMapChars.put(str2.charAt(i), count);
            } else {
                return false;
            }
        }
        return true;
}