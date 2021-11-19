#include <iostream>
using namespace std;

void function(int* a, int& n)
{
	cout << "Enter the position of a number you want chnaged by +1" << endl;
	cin >> n;
}
int main()
{
	int a[] = { 2,4,6,8,10 };
	int n;
	function(a, n);
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		if (i == n)
			a[i] = a[i] + 1;
	}
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		cout << a[i] << " ";
	}

	return 0;
}

