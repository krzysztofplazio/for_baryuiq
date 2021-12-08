#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>

using namespace std;

const int N = 100;

int main()
{
    int Z[N], i, ip, ik, isr, k, L, p, value = NULL;

    srand((unsigned)time(NULL));

    // wype³niamy tablicê Z [ ] 

    Z[0] = rand() % 5;
    for (i = 1; i < N; i++) 
    {
        Z[i] = Z[i - 1] + (rand() % 5);
    }

    // generujemy klucz k

    k = Z[0] + (rand() % (Z[N - 1] - Z[0] + 1));

    // poszukujemy binarnie elementu k

    p = -1; L = ip = 0; ik = N - 1;
    while (ip <= ik)
    {
        L++;
        isr = (ip + ik) >> 1;
        if (Z[isr] == k)
        {
            p = isr;
            value = Z[isr];
            break;
        }
        else if (k < Z[isr])
        {
            ik = isr - 1;
        }
        else
        {
            ip = isr + 1;
        }
    }

    // wyœwietlamy wyniki

    cout << k << ": ";
    if (p >= 0)
    {
        cout << p;
    }
    else
    {
        cout << "BRAK";
    }
    cout << ": obiegi = " << L << endl << endl;
    int temp = N;
    for (i = 0; i < temp; i++)
    {
        if (p >= 0 && k == Z[i])
        { 
            temp--;
            for (int j = i; j < temp; j++)
            {
                Z[j] = Z[j + 1];
            }
            i--;
        }
    } 
    for (i = 0; i < temp; i++)
    {
        cout << " ";
        cout << setw(3) << Z[i];
    }
    cout << endl << endl << "Dlugosc tablicy: " << temp << endl;
    return 0;
}