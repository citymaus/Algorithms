#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include "Sorting_and_Searching.h"
using namespace std;

int main()
{
	int start_s = clock();

	int s[4] = { 2, 4, 3, 1 };
	insertion_sort(s, 4);

	int stop_s = clock();
	cout << endl << "time: " << (stop_s - start_s) / double(CLOCKS_PER_SEC) << "sec" << endl;
	system("pause");
	return 0;
}