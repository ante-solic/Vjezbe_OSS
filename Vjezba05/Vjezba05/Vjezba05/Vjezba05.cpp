#include "Header.h"
#include <iostream>
using namespace std;

int main()
{
	srand(double(time(NULL)));

	int targetNumber;
	double min;
	double max;

	cout << "Enter the minimum range of random value: " << endl;
	cin >> min;

	cout << "Enter the maximum range of random value: " << endl;
	cin >> max;

	cout << "Number of targets you'll fire at: ";
	cin >> targetNumber;
	cout << endl;

	Gun g;
	Point p;
	int magazin;
	cout << "Enter magazin size of gun:" << endl;
	cin >> magazin;

	cout << "Gun position coordinates: ";
	p.setRandomValue(p, min, max);

	g.position = p;

	Target *arrayOfTargets;
	arrayOfTargets = new Target [targetNumber];

	for (int i = 0; i < targetNumber; ++i)
	{
		Target t;
		Point lowerLeft, upperRight;

		cout << i + 1 << ". lower Left point coordinates: ";
		lowerLeft.setRandomValue(lowerLeft, min, max);
		cout << i + 1 << ". upper Right pointcoordinates: ";
		upperRight.setRandomValue(upperRight, min, max);

		t.One = lowerLeft;
		t.Two = upperRight;

		arrayOfTargets[i] = t;
	}

	int hits = 0;
	while(magazin!=0)
	{
		Point bulletHole;
		cout << "Bullet hole coordinates: ";
		bulletHole.setRandomValue(bulletHole, min, max);

		if (((bulletHole.x = g.position.x) && (bulletHole.y = g.position.y)) || ((bulletHole.x = g.position.x) && (bulletHole.z = g.position.z)) || ((bulletHole.y = g.position.y) && (bulletHole.z = g.position.y)))
		{
			for (int i = 0; i < targetNumber; ++i)
			{
				if ((bulletHole.x <= sqrt((arrayOfTargets[i].Two.x - arrayOfTargets[i].One.x) * (arrayOfTargets[i].Two.x - arrayOfTargets[i].One.x))) && ((bulletHole.y <= sqrt((arrayOfTargets[i].Two.y - arrayOfTargets[i].One.y) * (arrayOfTargets[i].Two.y - arrayOfTargets[i].One.y))) && ((bulletHole.z <= sqrt((arrayOfTargets[i].Two.z - arrayOfTargets[i].One.z) * (arrayOfTargets[i].Two.z - arrayOfTargets[i].One.z))))))
				{
					hits++;
				}
			}
		}
		magazin = g.shoot(magazin);
	}

	cout << "You've hit " << hits << ". targets" << endl;
}
