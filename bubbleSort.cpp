#include<iostream>
#include <iomanip>
#include <math.h>

using namespace std;

void bubbleSort(int tam, int *v)
{
    int aux;
    //percorre todo o vetor
    for(int i=0; i<tam; i++)
    {
        for(int j=1; j<tam; j++)
        {
            if(v[j-1] > v[j])
            {
                aux = v[j];
                v[j] = v[j-1];
                v[j-1] = aux;
            }
        }
    }
}