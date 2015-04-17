

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