#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
#include <sstream>
using namespace std;

string firstNonRepeatingCharacter(string input) {
    map<char, int> freq;
    queue<char> newchars;
    string nonrepeating = "";
    stringstream ss;
    map<char, int>::iterator it;
    
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] != ' ')
        {
            it = freq.find(input[i]); 
            if (it != freq.end())
            {
                if (it->second == 1)
                {
                    newchars.pop();
                }
                freq[input[i]] += 1;
            }
            else
            {
                newchars.push(input[i]);
                freq.insert(pair<char, int> (input[i], 1));
            }
        }
    }
    ss << newchars.front();
    ss >> nonrepeating;
    return nonrepeating;
}