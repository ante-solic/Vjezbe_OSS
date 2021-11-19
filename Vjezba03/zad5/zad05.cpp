//Napisati funkciju koja broji koliko pojavljivanja danog podstringa 
//ima u stringu koristeæi funkcije standardne biblioteke.
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int counter_substr(string str, string substr)
{
    int counter = 0;
    int lenght_str = str.size();
    int lenght_substr = substr.size();
    int i, j;
    int br;
    int br2;
    for (i = 0, j = 0; i < lenght_str; i++)
    {
        if (str[i] == substr[j])
        {
            for (br = i, br2 = j; br2 < lenght_substr;)
            {
                if (str[br] == substr[br2])
                {
                    br++;
                    br2++;
                    continue;
                }
                else
                {
                    break;
                }
            }
            if (br2 < lenght_substr)
                continue;
            else
            {
                counter++;
                continue;
            }
        }
    }
    return counter;
}
int counter_substring1(string string1, string substr)
{
    int counter = 0;
    int position = 0;
    while ((position = string1.find(substr, position)) != string::npos)
    {
        counter++;
        position += substr.length();
    }
    return counter;
}
int main(void)
{
    string str, substr;
    cout << "enter the string and substring: ";
    cin >> str >> substr;
    int counter = counter_substr(str, substr);
    int counter1 = counter_substring1(str, substr);
    cout << counter << endl;
    cout << "drugi nacin je: " << counter1 << endl;
}





