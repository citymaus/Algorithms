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