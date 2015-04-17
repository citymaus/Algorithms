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