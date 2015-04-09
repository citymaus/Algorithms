#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <string>
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