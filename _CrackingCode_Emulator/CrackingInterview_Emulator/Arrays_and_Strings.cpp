#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <cstring>
#include "Arrays_and_Strings.h"
#include "file_handler.h"
#include <unordered_map>;
using namespace std;


void print_array(int arr[][100], int N)
{
  for (int x = 0; x < N; x++)
  {
    for (int y = 0; y < N; y++)
    {
      cout << arr[x][y] << " ";
    }
    cout << endl;
  }
}

//https://www.geeksforgeeks.org/check-if-a-string-can-be-formed-from-another-string-using-given-constraints/
bool string_in_a_string(string s1, string s2)
{
	unordered_map<char, int> map;

	for (int i = 0; i < s1.size(); i++) {
		map[s1[i]]++;
	}

	for (int i = 0; i < s2.size(); i++) {
		if (map[s2[i]]) {
			map[s2[i]]--;
		} else if (map[s2[i]-1] && map[s2[i]-2]) {
			map[s2[i] - 1]--;
			map[s2[i] - 2]--;
		}
		else {
			return false;
		}		
	}
	return true;
}

string replace_spaces(string s)
{
	string newstr = "";
	int length = s.length();
	cout << length << endl;
	int numspaces = 0;
	for (int i = 0; i < length; i++)
	{
		cout << i << ":" << s[i] << endl;
		if (s[i] == ' ')
		{
			numspaces++;
		}
	}
	cout << "ok" << endl;

	length = length + (numspaces*2);
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == ' ')
		{
			newstr += "%20";
		}
		else
		{
			newstr += s[i];
		}
	}
	return newstr;
}

string compression(string s)
{
	string newstr = "";
	int origlength = s.length();
	char p = s[0];
	int count = 0;

	for (int i = 1; i < s.length(); i++)
	{
		if (p != s[i])
		{
			newstr += p;
			count++;
			if (count > 1)
			{
				char buffer[100];
				char *intStr = itoa(count, buffer, 10);
				string str = string(intStr);
				newstr += str;
			}
			count = 0;
		}
		else
		{
			count++;
		}
		p = s[i];
	}
	newstr += p;
	if (count > 0)
	{
		char buffer[100];
		char *intStr = itoa(count, buffer, 10);
		string str = string(intStr);
		newstr += str;
	}

	if (newstr.length() == s.length())
	{
		newstr = s;
	}

	return newstr;
}

/*
  Given an image represented by an NxN matrix, where each pixel in the image is 4
  bytes, write a method to rotate the image by 90 degrees. Can you do this in place?
*/
void rotate_image(int arr[][100], int N)
{
  for (int layer = 0; layer < N / 2; layer++)
  {
    // arr[y][x]
    int first = layer;
    int last = N - 1 - layer;
    for (int x = first; x < last; x++)
    {
      int offset = x - first;

      // Save top
      int top = arr[first][x];
      
      // left(0, ?)->top(?, 0)
      arr[first][x] = arr[last - offset][first];

      // bottom -> left
      arr[last-offset][first] = arr[last][last - offset];

      // right -> bottom
      arr[last][last - offset] = arr[x][last];

      // top -> right
      arr[x][last] = top;
    }
  } 
}

/*
  Write an algorithm such that if an element in an MxN matrix is 0, its entire row and
  column are set to 0.
*/
void set_zeros(int arr[][100], int N)
{
    bool row[100];
    bool col[100];
    memset(row, false, sizeof(row));
    memset(col, false, sizeof(col));  

    // Store all rows and cols that contain a 0
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
      {
        if (arr[i][j] == 0)
        {
          row[i] = true;
          col[j] = true;
        }
      }
    }

    // Set rows and cols to 0
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
      {
        if (row[i] || col[j])
        {
          arr[i][j] = 0;
        }
      }
    }
}

/*
  Assume you have a method isSubstring which checks if one word is a substring
  of another. Given two strings, s1 and s2, write code to check If s2 is a rotation of s1
  using only one call to isSubstring (e.g., "waterbottLe" is a rotation of "erbottLewat").
*/
string is_rotation(string s1, string s2)
{
  /*
    si = xy = waterbottle
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

// Find last idx that is < checkVal
int findIdx(vector<int>& arr, stack<int>& s, int currIdx, int checkVal) {
	int candidate = (s.top() == INT_MAX) ? arr.size() - 1 : s.top();
	if (currIdx < 0 || currIdx >= arr.size()) {
		return candidate;
	}
	cout << "Current candidate idx:" << candidate << " val:" << arr[candidate] << endl;
	cout << "Is arr[" << currIdx << "]=" << arr[currIdx] << " < " << checkVal << endl;
	if (arr[currIdx] <= checkVal) {
		if (candidate <= currIdx) {
			s.push(currIdx);
			cout << " UPDATING candiate idx to " << currIdx << " (val " << arr[currIdx] << endl;
		}
		//int next = (arr.size() - currIdx) / 2;
		int next = 1;
		return findIdx(arr, s, currIdx + next, checkVal);
	}
	else {
		int next = (arr.size() - currIdx) / 2;
		return findIdx(arr, s, currIdx - next, checkVal);
	}
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	int total = nums1.size() + nums2.size();
	bool oneMedian = (total % 2 == 1);
	cout << "Num medians: " << ((oneMedian) ? "1" : "2") << endl;
	int firstMedianIdx, secondMedianIdx, firstMedianVal, secondMedianVal;
	int shiftMedIdx = 0;

	//TreeNode* small;
	//TreeNode* large;

	vector<int> first;
	vector<int> second;

	if (nums1.size() < nums2.size()) {
		firstMedianIdx = (nums2.size() / 2) - ((nums2.size() % 2 == 0) ? 1 : 0);
		secondMedianIdx = (nums1.size() / 2) - ((nums1.size() % 2 == 0) ? 1 : 0);
		first = nums2;
		second = nums1;
		//small = addToMinimalBST(nums1, 0, nums1.size()-1);
		//large = addToMinimalBST(nums2, 0, nums2.size()-1);
	}
	else {
		firstMedianIdx = (nums1.size() / 2) - ((nums1.size() % 2 == 0) ? 1 : 0);
		secondMedianIdx = (nums2.size() / 2) - ((nums2.size() % 2 == 0) ? 1 : 0);
		first = nums1;
		second = nums2;
		//small = addToMinimalBST(nums2, 0, nums2.size()-1);
		//large = addToMinimalBST(nums1, 0, nums1.size()-1);            
	}
	stack<int> biggestIdxLessThanMed;
	biggestIdxLessThanMed.push(INT_MAX);
	shiftMedIdx = findIdx(first, biggestIdxLessThanMed, secondMedianIdx, first[firstMedianIdx]);
	cout << "Shifting idx[" << firstMedianIdx << "] >> " << shiftMedIdx << endl;
	cout << "New median[" << (firstMedianIdx + shiftMedIdx) << "]" << endl;
	//cout << "SMALL TREE:" << endl;
	//printInOrder(small);
	//cout << endl;
	//cout << "LARGE TREE:" << endl;
	//printInOrder(large);
	//cout << endl;

	//TreeNode* merged = mergeTwoTrees(small, large);
	//cout << "MERGED TREE:" << endl;
	//printPretty(merged);
	//cout << endl;

	//cout << "small->data:" << small->data << endl;
	//cout << "large->data:" << large->data << endl;

	if (oneMedian) {

	}
	else {

	}
	return 0;
	//return ((small->data + large->data) / 2);
}