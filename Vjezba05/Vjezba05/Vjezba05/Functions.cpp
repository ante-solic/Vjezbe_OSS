#include "Header.h"
#include <iostream>
using namespace std;

void Point::setValue(Point& p)
{
	cout << "X: ";
	cin >> p.x;
	cout << "Y: ";
	cin >> p.y;
	cout << "Z: ";
	cin >> p.z;
}

void Point::setRandomValue(Point& p, double min, double max)
{
	p.x = fmod(rand(), max) + min;
	p.y = fmod(rand(), max) + min;
	p.z = fmod(rand(), max) + min;

	cout << endl << p.x << " " << p.y << " " << p.z << endl;
}

void Point::getValue(Point& p)
{
	
}

double Point::Distance2d(Point a, Point b)
{
	double distance = sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));

	return distance;
}

double Point::Distance3d(Point a, Point b)
{
	double distance = sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y) + (b.z - a.z) * (b.z - a.z));

	return distance;
}


int Gun::shoot(int ammo)
{
	ammo = ammo - 1;
	return ammo;	
}
