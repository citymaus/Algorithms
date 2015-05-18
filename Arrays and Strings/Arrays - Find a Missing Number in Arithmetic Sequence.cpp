#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int find_missing(vector<int> vec)
{
    int interval = 0;
    int last_interval = vec[1] - vec[0];
    int missing = -1;
    for (int i = 2; i < vec.size(); i++)
    {
        if (vec[i] - vec[i-1] == last_interval)
        {
            break;    
        }
        else
        {
            last_interval = vec[i] - vec[i-1];    
        }
    }
    for (int i = 1; i < vec.size(); i++)
    {
        if (vec[i] - vec[i-1] != last_interval)
        {
            missing = vec[i] - last_interval;
            break;
        }
    }
    return missing;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, j, result;
    cin >> n;
    
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> j;
        v.push_back(j);
    }
    result = find_missing(v);
    cout << result << endl;
    return 0;
}