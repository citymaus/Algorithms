#include <cstdio>
#include <string>
#include <stack>
using namespace std;

int calculate(string prefix)
{
    int retvalue = 0;
    stack<char> operations;
    for (int i = 0; i < prefix.length(); i++)
    {
        if (isOperator(prefix[i]))
        {
            int firstInt = operations.top();
            operations.pop();
            int secondInt = operations.top();
            operations.pop();

            operations.push(interim(prefix[i], firstInt - '0', secondInt - '0'));
        }
        else
        {
            operations.push(prefix[i]);
        }
    }
    retvalue = operations.top();
    return retvalue;
}

bool isOperator(char c)
{
    bool op = false;
    switch(c)
    {
        case '+':
            op = true;
            break;
        case '-':
            op = true;
            break;
        case '*':
            op = true;
            break;
        case '/':
            op = true;
            break;
        default:
            break;
    }
    return op;
}

int interim(char oper, int firstInt, int secondInt)
{
    int result = 0;
    
    switch(oper)
    {
        case '+':
            result = firstInt + secondInt;
            break;
        case '-':
            result = firstInt - secondInt;
            break;
        case '*':
            result = firstInt * secondInt;
            break;
        case '/':
            result = firstInt / secondInt;
            break;
        default:
            break;
    }
    return result;
}

void main() 
{
    string prefix = "+*123"; // = 5

}