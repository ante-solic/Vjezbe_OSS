#define Header

class Point
{
public:
	double x;
	double y;
	double z;
	void setValue(Point& p);
	void setRandomValue(Point& p, double min, double max);
	void getValue(Point& p);
	double Distance2d(Point a, Point b);
	double Distance3d(Point a, Point b);
};

class Gun
{
public:
	Point position;
	int shoot(int ammo);
};

class Target
{
public:
	Point One;
	Point Two;
	bool hit;
};