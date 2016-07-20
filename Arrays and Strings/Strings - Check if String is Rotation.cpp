/*
  Assume you have a method isSubstring which checks if one word is a substring
  of another. Given two strings, s1 and s2, write code to check If s2 is a rotation of s1
  using only one call to isSubstring (e.g., "waterbottLe" is a rotation of "erbottLewat").
*/
#include <string>
using namespace std;
string is_rotation(string s1, string s2)
{
  /*
    s1 = xy = waterbottle
    x = wat
    y = erbottle
    s2 = yx = erbottlewat
  */
  int yes = -1;

  int len = s1.length();

  // Make sure s1 and s2 are of equal length
  if (s1.length() == s2.length() && len > 0)
  {
    string s1s1 = s1 + s1;
    yes = s1s1.find(s2);
  }
  return (yes > -1) ? "rotation" : "not rotation";
}