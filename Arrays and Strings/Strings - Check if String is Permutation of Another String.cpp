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