#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include "file_handler.h"
#include "Arrays_and_Strings.h"
using namespace std; 

int numDigits(int number)
{
	int digits = 0;
	if (number < 0) digits = 1; // remove this line if '-' counts as a digit
	while (number) {
		number /= 10;
		digits++;
	}
	return digits;
}

int main() {
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int start_s=clock();
	
	// Change these based on challenge.
	string category = "arrays";
	string testname = "median";
	string testinput = category + "-" + testname + ".txt";
	FileHandler* filereader = new FileHandler(testinput);

#undef    ARRAY_INPUT
#undef   STRING_INPUT
#undef    LINE_INPUT
#define    VECTOR_INPUT

#undef   ARRAY_OUTPUT
#undef    VAR_OUTPUT
#undef	 BOOL_OUTPUT
#define INT_OUTPUT

  int n;
	int r;
	int t;
	int pairs;
	string s1, s2, string_result;
	vector<int> v1;
	vector<int> v2;
	bool bool_result;
	int int_result;
  cin >> n;

#ifdef LINE_INPUT
  // Grab line input
	getline(cin, s);
#endif
#ifdef ARRAY_INPUT  
  int arr[100][100];
  memset(arr, 0, sizeof(arr));

  // Grab array input
  for (int x = 0; x < n; x++)
  {
    for (int y = 0; y < n; y++)
    {
      cin >> r;
      arr[x][y] = r;
    }
  }
#endif
#ifdef STRING_INPUT
  cin >> s1 >> s2;
#endif
#ifdef VECTOR_INPUT
  cin >> s1;
  cin >> s2;
  cout << "S1:" << s1 << endl;
  cout << "S2:" << s2 << endl;
  for (int i = 0; i < s1.size(); i++) {
	  if (s1[i] != '[' && s1[i] != ']' && s1[i] != ' ' && s1[i] != ',') {
		  int p = (s1.find(',', i) != string::npos) ? s1.find(',', i) : s1.find(']', i);
		  string s = s1.substr(i, p - i);
		  int j = stoi(s);
		  v1.push_back(j);
		  if (numDigits(j) > 1) {
			  i = i + numDigits(j) - 1;
		  }
	  }
  }
  for (int i = 0; i < s2.size(); i++) {
	  if (s2[i] != '[' && s2[i] != ']' && s2[i] != ' ' && s2[i] != ',') {
		  int p = (s2.find(',', i) != string::npos) ? s2.find(',', i) : s2.find(']', i);
		  string s = s2.substr(i, p - i);
		  int j = stoi(s);
		  v2.push_back(j);
		  if (numDigits(j) > 1) {
			  i = i + numDigits(j) - 1;
		  }
	  }
  }
#endif

  //--------------------------------------------------
  // PRINT INPUT
  //--------------------------------------------------
	cout << endl << "INPUT:" << endl;
#ifdef ARRAY_INPUT
  print_array(arr, n);
#endif
#ifdef STRING_INPUT
  cout << s1 << " " << s2 << endl;
#endif
#ifdef VECTOR_INPUT
  cout << "vector<int> v1[";
  for (int i = 0; i < v1.size(); i++) {
	  cout << v1[i] << ((i == v1.size() - 1) ? "" : ", ");
  }
  cout << "]" << endl;
  cout << "vector<int> v2[";
  for (int i = 0; i < v2.size(); i++) {
	  cout << v2[i] << ((i == v2.size() - 1) ? "" : ", ");
  }
  cout << "]" << endl;
#endif
  
  //--------------------------------------------------
  // Current solution function
  //--------------------------------------------------
  //bool_result = string_in_a_string(s1, s2);
 // string_result = is_rotation(s1, s2);
  int_result = findMedianSortedArrays(v1, v2);

  
  //--------------------------------------------------
  // PRINT OUTPUT
  //--------------------------------------------------
	cout << endl << "OUTPUT:" << endl;
#ifdef ARRAY_OUTPUT
  print_array(arr, n);
#endif
#ifdef VAR_OUTPUT
  cout << string_result << endl;
#endif
#ifdef BOOL_OUTPUT
  if (bool_result) {
	  cout << "TRUE" << endl;
  }
  else {
	  cout << "FALSE" << endl;
  }
#endif
#ifdef INT_OUTPUT
  cout << ": " << int_result << endl;
#endif

  // End tests
	int stop_s=clock();
	cout << endl << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC) << "sec" << endl;
	system("pause");
  return 0;
}