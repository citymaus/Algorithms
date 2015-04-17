/*
  Replace all spaces in string 
*/
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