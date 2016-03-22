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

    // aaaabbcddd    
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] != ' ')
        {
            it = freq.find(input[i]); 
            if (it != freq.end())
            {
                // Character already exists
                if (it->second == 1)
                {
                    // Pop front of the queue, first entered character
                    //while(newchars.front() != input[i])
                    //{
                      //char temp = newchars.front();
                      newchars.pop();
                    //}
                }
                // Add to frequency char appears
                freq[input[i]] += 1;
            }
            else
            {
                // Add character to the back of the queue
                newchars.push(input[i]);
                // Add character frequency to map, start at 1
                freq.insert(pair<char, int> (input[i], 1));
            }
        }
    }
    ss << newchars.front();
    ss >> nonrepeating;
    return nonrepeating;
}