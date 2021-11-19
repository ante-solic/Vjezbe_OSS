/*Napisati funkciju u za uklanjanje elementa iz vektora sa što manje operacija.
Poredak elemenata u vektoru nije bitan.*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void input_vector(vector<int>& v, int el)
{
	int n;
	cout << "enter the members of the array: " << endl;
	for (int i = 0; i < el; i++)
	{
		cin >> n;
		v.push_back(n);
	}
}
void output_vector(vector<int> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
}
void delete_el(vector<int>& v,int index)
{
	int temp;
	temp = v[index];
	v[index] = v[v.size() - 1];
	v[v.size() - 1] = temp;
	v.pop_back();
}
int main(void)
{
	vector<int> v;
	int el;
	int el2;
	cout << "enter the number of members: " << endl;
	cin >> el;
	input_vector(v, el);
	cout << "enter the number of the member you want to delete: " << endl;
	cin >> el2;
	delete_el(v,el2-1);
	output_vector(v);
	return 0;
}


