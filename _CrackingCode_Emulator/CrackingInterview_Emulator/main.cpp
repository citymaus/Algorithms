#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include "file_handler.h"
#include "Strings.h"
using namespace std;


int main() {
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int start_s=clock();

	// Change these based on challenge.
#define current_level Search
#define current_test  sherlock_and_pairs
	string category = "strings";
	string testname = "compression"; //"flipping_bits"; //"the_love_letter";
	string testinput = category + "-" + testname + ".txt";
	FileHandler* filereader = new FileHandler(testinput);

    int n;
	int r;
	int t;
	int pairs;
	string s;
	getline(cin, s);
	cout << "INPUT:" << endl << s << endl << endl;
	cout << "OUTPUT:" << endl;
	cout << compression(s) << endl;
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