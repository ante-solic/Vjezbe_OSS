#include <iostream>
using namespace std;

int minimum(int *a,int n)
{
    if (n == 1)
        return a[0];
    return min(a[n - 1], minimum(a, n - 1));
}

int maximum(int* a, int n)
{
    if (n == 1)
        return a[0];
    return max(a[n - 1], maximum(a, n - 1));
}


int main()
{
    int a[] = { 12,6,5,31,24 };
    int p = maximum(a, sizeof(a) / sizeof a[0]);
    int r = minimum(a, sizeof(a) / sizeof a[0]);
    cout << p << " " << r << endl;
}


