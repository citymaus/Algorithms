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
using namespace std;

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