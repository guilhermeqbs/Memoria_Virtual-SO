#include<iostream>
#include <iomanip>
#include <math.h>

using namespace std;

void bubbleSort(int n, int *p, int *y, int *s)
{
    int auxP, auxY, auxS;
    //percorre todo o vetor
    for(int i=0; i<n; i++)
    {
        for(int j=1; j<n; j++)
        {
            if(y[j-1] > y[j])
            {
                auxP = p[j];
                p[j] = p[j-1];
                p[j-1] = auxP;

                auxY = y[j];
                y[j] = y[j-1];
                y[j-1] = auxY;

                auxS = s[j];
                s[j] = s[j-1];
                s[j-1] = auxS;
            }
        }
    }
}