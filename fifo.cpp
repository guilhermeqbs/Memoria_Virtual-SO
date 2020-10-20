#include <iostream>
#include <iomanip>
#include "escrita.cpp"

using namespace std;

void fifo(int n,int *y, int *s)
{   
    int copias;

    int espera[n]; //vetor que armazena o valor de espera de cada processo
    int  posicao = 0;
    float mediaEspera = 0, somaEspera = 0, mediaResposta = 0 ;
  
    posicao = y[0];// set a posicaao no inico do primeiro processo

    for(int i=0; i<n; i++)
    {
        espera[i] =  posicao - y[i];
        posicao += s[i];
    }

    //calculo da media de espera.
    for(int i=0; i<n; i++)
    {
        somaEspera += espera[i];
    }
    mediaEspera = somaEspera/n;
    mediaResposta = mediaEspera;

    saidaArquivo("FIFO ",mediaEspera,mediaResposta);
}

