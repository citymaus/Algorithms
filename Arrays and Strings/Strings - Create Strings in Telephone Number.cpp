#include <cstdio>
#include <string>
#include <sstream>
using namespace std;

char* getChars(char n, int &numchars);
void findwords(int val);
void permutation(string prefix, string suffix);

void main() {
    findwords(1345054398);
}

void findwords(int val)
{
    int a = val;
    stringstream ss;
    ss << a;
    string str = ss.str();
    permutation("", str);
}

void permutation(string prefix, string suffix) 
{
    if(suffix.length() == 0) 
        printf("%s", prefix);
    else{
        int numchars = 0;
        char* chars = getChars(suffix[0], numchars);
        if (numchars>0) {
            for(int c = 0; c < numchars; c++)
            {
                permutation(prefix + chars[c], suffix.substr(1, suffix.length()-1));
            }

        } else {
            permutation(prefix, suffix.substr(1, suffix.length()-1));
        }
    }
}

char* getChars(char n, int &numchars) {
    char* possible = NULL;
    numchars = 0;

    switch (n) {
    case '1':
        numchars = 0;
        char one[1] = {'-'};
        possible = one;

    case '2':
        numchars = 3;
        char two[3] = { 'a', 'b', 'c' };
        possible = two;

    case '3':
        numchars = 3;
        char three[3] = { 'd', 'e', 'f' };
        possible = three;

    case '4':
        char[] four = { 'g', 'h', 'i' };
        return four;

    case '5':
        char[] five = { 'j', 'k', 'l' };
        return five;

    case '6':
        char[] six = { 'm', 'n', 'o' };
        return six;

    case '7':
        char[] seven = { 'p', 'q', 'r', 's'};
        return seven;

    case '8':
        char[] eight = { 't', 'u', 'v' };
        return eight;

    case '9':
        char[] nine = { 'w', 'x', 'y', 'z'};
        return nine;

    case '0':
        char[] zero = {};
        return zero;
    }

    return possible;
}