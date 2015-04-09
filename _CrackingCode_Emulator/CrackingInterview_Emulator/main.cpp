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
#define current_level Search
#define current_test  sherlock_and_pairs
	string category = "strings";
	string testname = "rotate"; //"flipping_bits"; //"the_love_letter";
	string testinput = category + "-" + testname + ".txt";
	FileHandler* filereader = new FileHandler(testinput);

#define   ARRAY_INPUT
#undef    LINE_INPUT
#undef    VECTOR_INPUT

  int n;
	int r;
	int t;
	int pairs;
	string s;
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

	cout << "INPUT:" << endl;
#ifdef ARRAY_INPUT
  print_array(arr, n);
#endif
  
  // Current solution function
  rotate_image(arr, n);

	cout << "OUTPUT:" << endl;
#ifdef ARRAY_INPUT
  print_array(arr, n);
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
	//current_level::current_test(outrow, 0, n-1);
	//current_level::current_test(countme, thestrings);
	*/
	int stop_s=clock();
	cout << endl << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC) << "sec" << endl;
	system("pause");
    return 0;
}