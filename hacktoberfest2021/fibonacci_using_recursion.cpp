#include<iostream>
using namespace std;

/*
Task:
1. WAP tp print fibonacci series till n using recursion
*/

int recursion(int n)
{
    if (n ==1 || n==0)
        return n;
    return recursion(n - 1) + recursion(n - 2);
}
int main()
{
    int n;
    cin >> n;
    cout << recursion(n);

    return 0;
}
