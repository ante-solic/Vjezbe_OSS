#include <iostream>
#include <cstdlib>
#include <random>
#include <fstream>
#include <cctype>
#include "Header.h"

using namespace std;

int main()
{
    HangmanModel model;
    HangmanController controller;
    HangmanView view;

    string Movie,HiddenName,usedLetters;
    int score;
    score = model.lives;
    char userLetter;
    int userGuess;

    srand((unsigned int)time(NULL));
    unsigned int randNum = rand() % (36 - 0 + 1) + 0;

    ifstream File;
    File.open("movie.txt");
    if (!File)
    {
        cout << "Datoteka ne postoji! ";
    }

    HiddenName = model.Nameofmovie(randNum, File);
    Movie = model.movie;
    for (int i = 0; i < Movie.size(); i++)
    {
        Movie[i] = tolower(Movie[i]);
    }

    while (model.inGame)
    {
        userLetter = view.userEntry();
        userGuess = view.checkLetter(Movie,HiddenName,userLetter);
        if (userGuess == 0)
        {
            view.updateLives(score);
        }
        else
        {
            controller.displayUsedLetters(Movie,HiddenName, userLetter);
        }
        cout << endl;
        controller.diplayCurrentProgress(HiddenName, score);
        controller.displayHangman(score);
        model.inGame = view.checkifGameisOver(HiddenName,score);
    }
    cout << "GAME OVER!" << endl;
    if (score > 0)
        cout << "You Won!" << endl;
    else
        cout << "You lost! Correct answer was: " << Movie << endl;

    return 0;
}

