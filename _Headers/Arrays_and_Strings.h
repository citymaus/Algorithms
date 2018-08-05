#include <stdio.h>
#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
using namespace std;

void printVector(vector<int>& v);

void printVector(vector<int>& v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
}