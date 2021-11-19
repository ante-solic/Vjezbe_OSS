/*Koristeæi STL funkcije sortirajte vektor, ubacite 0 ispred najmanjeg elementa, te
sumu svih elemenata iza najveæeg elementa.*/
#include <iostream>
#include <vector>
#include <string>
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
void sort_vector(vector <int>& v)
{
	int sum = 0;
	int a = 0;
	for (int i = 0; i < v.size(); i++)
	{
		sum = sum + v[i];
	}
	sort(v.begin(), v.end());
	v.insert(v.begin(), a);
	v.push_back(sum);
}
void output_vector(vector<int> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
}
int main(void)
{
	vector<int> v;
	int el;
	cout << "enter the number of members: " << endl;
	cin >> el;
	input_vector(v,el);
	sort_vector(v);
	output_vector(v);
	return 0;


}