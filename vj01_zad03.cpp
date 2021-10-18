#include <iostream>
using namespace std;

int minimum(int* a, int n)
{
    int min = a[0];
    for (int i = 0; i < n; i++)
    {
        if (min < a[i])
            min = a[i];
    }

    return min;
}

int maximum(int* a, int n)
{
    int max = a[0];
    for (int i = 0; i < n; i++)
    {
        if (max > a[i])
            max = a[i];
    }

    return max;
}

int main()
{
    int a[] = { 12,6,5,31,24 };
    int p = maximum(a, sizeof(a) / sizeof a[0]);
    int r = minimum(a, sizeof(a) / sizeof a[0]);
    cout << p << " " << r << endl;
}

