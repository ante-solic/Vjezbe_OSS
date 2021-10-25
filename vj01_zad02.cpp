#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct matrix
{
    int m;
    int n;
    float a;
    float b;
    float** mat_i_j;
};


void input(matrix* mat, int c)
{
    cout << "unesite broj redaka i broj stupaca matrice:" << endl;
    cin >> mat[c].m;
    cin >> mat[c].n;
    cout << "unesite brojeve a i b:" << endl;
    cin >> mat[c].a;
    cin >> mat[c].b;
    cout << endl;
}

void generating(matrix* mat, int c)
{
    if (c == 5 || c == 6)
    {
        mat[c].mat_i_j = new float* [mat[c - 5].n];

        for (int counter = 0; counter < mat[c - 5].n; counter++)
        {
            mat[c].mat_i_j[counter] = new float[mat[counter].m];
        }
    }
    if (c == 3)
    {
        mat[c].mat_i_j = new float* [mat[0].m];

        for (int counter = 0; counter < mat[1].n; counter++)
        {
            mat[c].mat_i_j[counter] = new float[mat[counter].n];
        }
    }

    if (c == 2 || c == 4)
    {
        mat[c].mat_i_j = new float* [mat[0].m];

        for (int counter = 0; counter < mat[0].m; counter++)
        {
            mat[c].mat_i_j[counter] = new float[mat[counter].n];
        }
    }

    if (c < 2)
    {
        mat[c].mat_i_j = new float* [mat[c].m];

        for (int counter = 0; counter < mat[c].m; counter++)
        {
            mat[c].mat_i_j[counter] = new float[mat[0].n];
        }
        srand(time(NULL));

        for (int i = 0; i < mat[c].m; i++)
        {
            for (int j = 0; j < mat[c].n; j++)
            {
                mat[c].mat_i_j[i][j] = (mat[c].b - mat[c].a) * ((((float)rand()) / (float)RAND_MAX)) + mat[c].a;
            }
        }
        cout << endl;
    }
}

void addition(matrix* mat)
{

    if ((mat[0].m == mat[1].m) && (mat[0].n == mat[1].n))
    {
        for (int i = 0; i < mat[1].m; ++i)
            for (int j = 0; j < mat[1].n; ++j)
            {
                mat[2].mat_i_j[i][j] = mat[0].mat_i_j[i][j] + mat[1].mat_i_j[i][j];
            }
    }
    else
        cout << "Matrice nisu kompatibilne za zbrajanje" << endl << endl;
}

void subtraction(matrix* mat)
{
    if ((mat[0].m == mat[1].m) && (mat[0].n == mat[1].n))
    {
        for (int i = 0; i < mat[1].m; ++i)
            for (int j = 0; j < mat[1].n; ++j)
            {
                mat[4].mat_i_j[i][j] = mat[0].mat_i_j[i][j] - mat[1].mat_i_j[i][j];
            }
    }
    else
        cout << "Matrice nisu kompatibilne za oduzimanje" << endl << endl;
}

void multiplication(matrix* mat)
{
    if (mat[0].n == mat[1].m)
    {
        for (int i = 0; i < mat[0].m; ++i)
            for (int j = 0; j < mat[1].n; ++j)
            {
                mat[3].mat_i_j[i][j] = 0;
            }

        for (int i = 0; i < mat[0].m; ++i)
            for (int j = 0; j < mat[1].n; ++j)
            {
                for (int k = 0; k < mat[0].n; ++k)
                {
                    mat[3].mat_i_j[i][j] += mat[0].mat_i_j[i][k] * mat[1].mat_i_j[k][j];
                }
            }
    }
    else
        cout << "matrice nisu pogodne za množenje" << endl << endl;
}

void trans_matrix(matrix* mat, int trans)
{
    for (int i = 0; i < mat[trans].m; ++i)
        for (int j = 0; j < mat[trans].n; ++j)
        {
            mat[5 + trans].mat_i_j[j][i] = mat[trans].mat_i_j[i][j];
        }
}

void output(matrix* mat)
{
    for (int c = 0; c < 2; c++)
    {
        cout << c + 1 << ". Matrica: " << endl;
        for (int i = 0; i < mat[c].m; i++)
        {
            for (int j = 0; j < mat[c].n; j++)
            {
                cout << mat[c].mat_i_j[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    if ((mat[0].m == mat[1].m) && (mat[0].n == mat[1].n))
    {
        cout << endl << "zbroj matrica je : " << endl;
        for (int i = 0; i < mat[0].m; ++i)
            for (int j = 0; j < mat[0].n; ++j)
            {
                cout << mat[2].mat_i_j[i][j] << "  ";
                if (j == mat[0].n - 1)
                    cout << endl;
            }
        cout << endl;

        cout << endl << "razlika matrica je : " << endl;
        for (int i = 0; i < mat[0].m; ++i)
            for (int j = 0; j < mat[0].n; ++j)
            {
                cout << mat[4].mat_i_j[i][j] << "  ";
                if (j == mat[0].n - 1)
                    cout << endl;
            }
        cout << endl;
    }
    if (mat[0].n == mat[1].m)
    {
        cout << "umnožak matrica je:" << endl;
        for (int i = 0; i < mat[0].m; i++)
        {
            for (int j = 0; j < mat[1].n; j++)
            {
                cout << mat[3].mat_i_j[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }


    for (int trans = 0; trans < 2; trans++)
    {
        // Printing the transpose
        cout << "Transponirana matrica od " << trans + 1 << ". matrice je :" << endl;
        for (int i = 0; i < mat[trans].n; ++i)
            for (int j = 0; j < mat[trans].m; ++j)
            {
                cout << " " << mat[5 + trans].mat_i_j[i][j];
                if (j == mat[trans].m - 1)
                    cout << endl << endl;
            }
    }

}

void free(matrix* mat)
{
    delete mat;
}

int main()
{
    int num = 7;
    matrix* mat = new matrix[num];

    for (int c = 0; c < num; c++)
    {
        if (c < 2)
        {
            input(mat, c);
        }
        generating(mat, c);
    }
    addition(mat);
    subtraction(mat);
    multiplication(mat);

    for (int trans = 0; trans < 2; trans++) //2 stands for two input matrixes
        trans_matrix(mat, trans);

    output(mat);
    free(mat);
}

