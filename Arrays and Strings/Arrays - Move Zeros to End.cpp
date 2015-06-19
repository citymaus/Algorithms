
#include <cstdio>
#include <algorithm>
using namespace std;

void move_zeros(int A[])
{
    int i = 0;
    for (int j = 0; j < sizeof(A)/sizeof(int); j++) 
    {
        if (A[j] != 0) 
        {
            swap(A[i], A[j]);
            i++;
        }
    }
}