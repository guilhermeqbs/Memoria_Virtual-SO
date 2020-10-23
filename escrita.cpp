#include <iostream>
#include <fstream>
#include <string>
#include <locale.h>
#include <stdio.h>
#include <string.h>

using namespace std;

//produz o arquivo com os resultados esperados
void saidaArquivo(int contado, int *mf, int tamf){

    ofstream saida;

    saida.open("saida.txt", ios::out);

    saida <<contado <<endl;
    
        for(int i=0; i<tamf; i++)
        {
            saida<< mf[i] <<" ";
        }
    

    saida.close();
}