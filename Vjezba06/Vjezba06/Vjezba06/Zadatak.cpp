#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <cctype>
#include<algorithm>
#include "Header.h"

using namespace std;


string HangmanModel::Nameofmovie(int randNum, ifstream& File)
{
	char ch = '_';
	char space = ' ';
	char chars[] = ":'-";
	for (int i = 0; i < randNum; i++)
	{
		getline(File, movie);
	}

	for (unsigned int i = 0; i < strlen(chars); ++i)
	{
		movie.erase(std::remove(movie.begin(), movie.end(), chars[i]), movie.end());
	}

	for (size_t i = 0; i < movie.size(); i++) 
	{
		if(isalpha(movie[i]))
		{
			guessmovie.push_back(ch);
		}
		else if (isspace(movie[i]))
		{
			guessmovie.push_back(space);
		}
	}
	cout << guessmovie << endl;
	cout << endl;
	return guessmovie;
}

char HangmanView::userEntry()
{
	char letter;
	do {
		cout << "Enter lowercase letter: " << endl;
		cin >> letter;
	} while (isupper(letter));
	return letter;
}

int HangmanView::checkLetter(string Movie,string HiddenName,char userLetter)
{
	int n = Movie.size();
	int counter = 0;
	for (int i = 0; i < n; i++)
	{
		if (Movie[i] == userLetter)
		{
			return 1;
		}
	}
	return 0;
}

void HangmanController::displayUsedLetters(string Movie,string& HiddenName,char userLetter)
{
	int n = HiddenName.size();
	for (int i = 0; i < n; i++)
	{
		if (Movie[i] == userLetter)
		{
			HiddenName[i] = userLetter;
		}
	}
}

void HangmanController::diplayCurrentProgress(string HiddenName,int score)
{
	cout << "Current progress is: " << HiddenName << endl;
	cout << "Remaining lives: " << score << endl;
}

void HangmanView::updateLives(int& score)
{
	score--;
}

int HangmanView::checkifGameisOver(string HiddenName,int score)
{
	int counter=0;
	for (int i = 0; i < HiddenName.size(); i++)
	{
		if (HiddenName[i] == '_')
		{
			counter++;
			break;
		}
	}
	if (score > 0 && counter > 0)
		return 1;
	return 0;
}

void HangmanController::displayHangman(int score)
{
	if (score == 8)
	{
		cout << "_______  " << endl <<
			"|  /     " << endl <<
			"| /      " << endl <<
			"|/       " << endl <<
			"|        " << endl <<
			"|        " << endl <<
			"|        " << endl <<
			"|________" << endl;
	}
	else if (score == 7)
	{
		cout << "_______  " << endl <<
			"|  /  |  " << endl <<
			"| /      " << endl <<
			"|/       " << endl <<
			"|        " << endl <<
			"|        " << endl <<
			"|        " << endl <<
			"|________" << endl;
	}
	else if (score == 6)
	{
		cout << "_______  " << endl <<
			"|  /  |  " << endl <<
			"| /   O  " << endl <<
			"|/       " << endl <<
			"|        " << endl <<
			"|        " << endl <<
			"|        " << endl <<
			"|________" << endl;
	}
	else if (score == 5)
	{
		cout << "_______  " << endl <<
			"|  /  |  " << endl <<
			"| /   O  " << endl <<
			"|/   /   " << endl <<
			"|        " << endl <<
			"|        " << endl <<
			"|        " << endl <<
			"|________" << endl;
	}
	else if (score == 4)
	{
		cout << "_______  " << endl <<
			"|  /  |  " << endl <<
			"| /   O  " << endl <<
			"|/   /|  " << endl <<
			"|        " << endl <<
			"|        " << endl <<
			"|        " << endl <<
			"|________" << endl;
	}
	else if (score == 3)
	{
		cout << "_______  " << endl <<
			"|  /  |  " << endl <<
			"| /   O  " << endl <<
			"|/   /|\\" << endl <<
			"|        " << endl <<
			"|        " << endl <<
			"|        " << endl <<
			"|________" << endl;
	}
	else if (score == 2)
	{
		cout << "_______  " << endl <<
			"|  /  |  " << endl <<
			"| /   O  " << endl <<
			"|/   /|\\" << endl <<
			"|     |  " << endl <<
			"|        " << endl <<
			"|        " << endl <<
			"|________" << endl;
	}
	else if (score == 1)
	{
		cout << "_______  " << endl <<
			"|  /  |  " << endl <<
			"| /   O  " << endl <<
			"|/   /|\\" << endl <<
			"|     |  " << endl <<
			"|    /   " << endl <<
			"|        " << endl <<
			"|________" << endl;
	}
	else
	{
		cout << "_______  " << endl <<
			"|  /  |  " << endl <<
			"| /   O  " << endl <<
			"|/   /|\\" << endl <<
			"|     |  " << endl <<
			"|    / \\" << endl <<
			"|        " << endl <<
			"|________" << endl;
	}
}