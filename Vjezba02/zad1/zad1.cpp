#include <iostream>
using namespace std;

void min(int *a,int &b)
{
	b = a[0];
	for (int i = 0; i < 5; i++)
	{
		if (a[i]<b)
		{
			b = a[i];
		}

	}
}
void max(int* a, int& c)
{
	c = a[0];
	for (int i = 0; i < 5; i++)
	{
		if (a[i] > c)
		{
			c = a[i];
		}
	}
}

int main()
{
	int a[] = {12,5,28,3,16};
	int b;
	int c;
	min(a, b);
	max(a, c);
	cout << "Najmanji broj je " << b << ", a najveci " << c << endl;
	return 0;
}
