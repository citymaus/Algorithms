#include <cstdio>
#include <queue>
#include <cstdlib>
using namespace std;
 
queue<int> q1;
queue<int> q2;
 
int push(int data)
{  
    q1.push(data);
}
 
int pop()
{
    while(q1.size() != 1)
    {
        q2.push(q1.front());
        q1.pop();
    }

    int temp = q1.front();
    q1.pop();
    queue<int> t = q1;
    q1 = q2;
    q2 = t;
    return temp;
} 
 
int main(void)
{
    push(10);
    push(20);
    push(30);
    printf("%d\n",pop());
    push(40);
    printf("%d\n",pop());
    printf("%d\n",pop());
    getchar();
    return 0;
}