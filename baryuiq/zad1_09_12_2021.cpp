// Wyszukiwanie lidera
// Data:   4.05.2008
// (C)2020 mgr Jerzy Wa³aszek
//---------------------------

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>

using namespace std;

const int N = 85;

int main()
{
    int Z[N], W, counter = 0;

    srand((unsigned)time(NULL));

    // Wype³niamy tablicê
    cout << "Tablica: ";
    W = rand() % 100;
    for (int i = 0; i < N; i++)
    {
        if (rand() % 2)
        {
            Z[i] = rand() % 100;
        }
        else
        {
            Z[i] = W;
        }
        cout << Z[i] << " ";
    }
    cout << endl << endl;
    for (int i = N - 1; i >= 0; i--)
    {
        if (Z[i] == Z[i - 1])
        {
            counter += 2;
            int temp = Z[i];
            for (int j = i - 1; j >= 0; j--)
            {
                if (temp != Z[j])
                {
                    i = j;
                    break;
                }
                counter++;
            }
        }
    }
    if (counter > N * 0.5)
    {
        cout << "Lider to: " << W << ". Wystapil ponad " << counter << " razy.";
    }
    else
    {
        cout << "Brak lidera :(.";
    }
    return 0;
}