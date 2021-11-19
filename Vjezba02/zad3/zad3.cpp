#include <iostream>
#include<cmath>
using namespace std;

struct rectangle
{
    int x1;
    int y1;
    int x2;
    int y2;
};

struct circle
{
    int xs;
    int ys;
    int r;
};

int intersect(rectangle* rect, const circle& cir, int n)
{
    int counter = 0;
    for (int i = 0; i < n; i++)
    {
        if (cir.ys >= rect[i].y1)
        {  
            if (rect[i].x1 <= cir.xs && rect[i].x2 >= cir.xs)
            {
                if (abs(rect[i].y1 - cir.ys) <= cir.r)
                {
                    counter++;
                }
            }
            else if (((rect[i].x1 - cir.xs) * (rect[i].x1 - cir.xs) + (rect[i].y1 - cir.r) * (rect[i].y1 - cir.r) <= cir.r * cir.r) || ((rect[i].x2 - cir.xs) * (rect[i].x2 - cir.xs) + (rect[i].y1 - cir.r) * (rect[i].y1 - cir.r) <= cir.r * cir.r))
            {
                counter++;
            }
        }
        else
        {
            if (rect[i].x1 <= cir.xs && rect[i].x2 >= cir.xs)
            {
                if (abs(rect[i].y2 - cir.ys) <= cir.r)
                {
                    counter++;
                }
            }
            else if (((rect[i].x1 - cir.xs) * (rect[i].x1 - cir.xs) + (rect[i].y2 - cir.r) * (rect[i].y2 - cir.r) <= cir.r * cir.r) || ((rect[i].x2 - cir.xs) * (rect[i].x2 - cir.xs) + (rect[i].y2 - cir.r) * (rect[i].y2 - cir.r) <= cir.r * cir.r))
            {
                counter++;
            }
        }
        
    }
    return counter;
}

int main()
{
    int n;
    cout << "Enter number of rectangles: " << endl ;
    cin >> n;
    cout << endl;

    rectangle* rect = new rectangle[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter values for " << i + 1 << ". rectangle: " << endl << endl;
        cout << "Enter lower left x value: " << endl;
        cin >> rect[i].x1;
        cout << "Enter lower left y value: " << endl;
        cin >> rect[i].y1;
        do {
            cout << "Enter upper right x value: " << endl;
            cin >> rect[i].x2;
            if (rect[i].x1 > rect[i].x2)
                cout << "lower left value of x needs to be smaller then upper right value of x!" << endl;
        } while (rect[i].x1 > rect[i].x2);
        do {
            cout << "Enter upper right y value: " << endl;
            cin >> rect[i].y2;
            if (rect[i].y1 > rect[i].y2)
                cout << "lower left value of y needs to be smaller then upper right value of y!" << endl;
        } while (rect[i].y1 > rect[i].y2);
        cout << endl;
    }

    circle cir;
    cout << "Enter the coordinates of the center of the circle" << endl;
    cin >> cir.xs;
    cin >> cir.ys;
    cout << "Enter the radius of the circle:" << endl;
    cin >> cir.r;

    cout << "Broj pravokutnika koji sijeku kruznicu je: " << intersect(rect, cir, n) << endl;

    return 0;
}
