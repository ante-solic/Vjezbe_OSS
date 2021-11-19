#include <iostream>
using namespace std;

struct Vector
{
    int* arr;
    unsigned int size_arr, capacity;
    //funkcije
    void vector_new(int sz);
    void vector_delete();
    void vector_push_back(int n);
    void vector_pop_back();
    int vector_front();
    int vector_back();
    int vector_size_arr();
    void print_vector();
};
void Vector::vector_new(int sz)
{
    arr = new int[sz];
    size_arr = 0;
    capacity = sz;
}
void Vector::vector_delete()
{
    delete[] arr;
}
void Vector::vector_push_back(int n)
{
    if (size_arr == capacity)
    {
        capacity *= 2;
        int* new_arr = new int[capacity];
        for (int i = 0; i < capacity - 1; i++)
        {
            new_arr[i] = arr[i];
        }

        delete arr;
        arr = new_arr;
    }

    arr[size_arr] = n;
    size_arr++;
}


void Vector::vector_pop_back()
{
    size_arr = size_arr - 1;
}
int Vector::vector_front()
{
    return arr[0];
}
int Vector::vector_back()
{
    return arr[size_arr - 1];
}
int Vector::vector_size_arr()
{
    return size_arr;
}
void Vector::print_vector()
{
    for (int i = 0; i < vector_size_arr(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main(void)
{
    Vector vektor;
    vektor.vector_new(4);
    int el;
    cout << "Unesite elemente niza a za prekid unesite broj 0: " << endl;
    cin >> el;
    while (el != 0)
    {
        vektor.vector_push_back(el);
        cin >> el;
    }

    vektor.print_vector();
    cout << "prvi element niza je: " << vektor.vector_front() << endl;
    cout << "zadnji element niza je: " << vektor.vector_back() << endl;

    cout << "broj clanova niza je: " << vektor.vector_size_arr() << endl;
    cout << "kapacitet niza je:  " << vektor.capacity << endl;

    cout << "niz bez zadnjeg elementa: " << endl;
    vektor.vector_pop_back();
    vektor.print_vector();
    vektor.vector_delete();
}