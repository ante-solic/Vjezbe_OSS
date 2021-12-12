#define Header

using namespace std;

class HangmanModel //opisuje rečenicu koju treba pogoditi, trenutno stanje rečenice koju gradimo, slova koja su pogođena i slično
{
public:
		string movie;
		string guessmovie;
		int lives = 8;
		bool inGame=true;
		string Nameofmovie(int randNum,ifstream& File); 
};

class HangmanController //omogućuje i verificira unos, updatea prikaz, modificira model
{
public:
	void diplayCurrentProgress(string HiddenName,int score);
	void displayUsedLetters(string Movie,string& HiddenName, char userLetter);
	void displayHangman(int score);
};

class HangmanView: public HangmanController //opisuje prikaz vješala, prikaz trenutnog stanja rečenice koja se gradi i prikaz pogođenih / promašenih slova
{
public:
	char userEntry();
	int checkLetter(string Movie,string HiddenName,char userLetter);
	void updateLives(int &score);
	int checkifGameisOver(string HiddenName,int score);
};

