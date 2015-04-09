#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include "file_handler.h"
#include "Arrays_and_Strings.h"
using namespace std;


int main() {
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int start_s=clock();

	// Change these based on challenge.
	string category = "strings";
	string testname = "rotatestr";
	string testinput = category + "-" + testname + ".txt";
	FileHandler* filereader = new FileHandler(testinput);

#undef    ARRAY_INPUT
#define   STRING_INPUT
#undef    LINE_INPUT
#undef    VECTOR_INPUT

#undef   ARRAY_OUTPUT
#define    VAR_OUTPUT

  int n;
	int r;
	int t;
	int pairs;
	string s1, s2, result;
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
  
  //--------------------------------------------------
  // Current solution function
  //--------------------------------------------------
  result = is_rotation(s1, s2);

  
  //--------------------------------------------------
  // PRINT OUTPUT
  //--------------------------------------------------
	cout << endl << "OUTPUT:" << endl;
#ifdef ARRAY_OUTPUT
  print_array(arr, n);
#endif
#ifdef VAR_OUTPUT
  cout << result << endl;
#endif

	//cout << rotate_image(arr, n) << endl;
//    string row, s;
    //unsigned int input;
	//unsigned int opers;
    //cin >> n;    
    //cin >> T;
	//vector <int> countme;
    //vector <string> thestrings;
	/*for (int j = 0; j < T; j++)
	{
		//cout << "TESTCASE " << j << ":" << endl;
		cin >> n;
        vector <int> v;
		for(int i = 0; i < n; i++) 
		{
			//cin >> input;
			opers = current_level::current_test(input);
			cout << opers << endl; 
			cin >> r;
			v.push_back(r);
			//thestrings.push_back(s);
		}
		ArraysSorting::quick_sort4(v, 0, v.size()-1);
        //ArraysSorting::print_arr(v);
        //cout << endl;
        pairs = current_level::current_test(v);
        cout << pairs << endl;
	}
  */

  // End tests
	int stop_s=clock();
	cout << endl << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC) << "sec" << endl;
	system("pause");
  return 0;
}