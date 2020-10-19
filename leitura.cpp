#include <iostream>
#include <fstream>
#include <string>
#include <locale.h>
#include <stdio.h>
#include <string.h>

#include "fifo.cpp"
#include "prio.cpp"
#include "srt.cpp"
#include "rrq.cpp"
#include "bubbleSort.cpp"

int *aux1, *aux2, k=0;
int *p, *y, *s, n, j=-1, aux;
int *copyS;

using namespace std;


void entradaArquivo(string nomeTXT);
void quebrarLinha(string linha);//Quebra a linha do arquivo em interos
char *convercaoStringParaChar(string linha);
int tamArquivo(string nomeTXT);
void resetaS();
void copiavS();

//realiza a leitura do arquivo de entrada com os dados dos processos
int main(){
    
    setlocale(LC_ALL,NULL);
   
    string nomeTXT = "entrada.txt";

    cout<<"\nO arquivo 'entrada.txt' vai ser lido...\n\n";
    
    n = tamArquivo(nomeTXT);

    //alocacao dos vetores
    aux1 = new int[n];
    aux2 = new int[n*n];
    copyS = new int[n];
    p = new int[n];
    y = new int[n];
    s = new int[n];

    entradaArquivo(nomeTXT);
    
    for(int i=0; i<n; i++)
    {
        p[i] = aux1[i];
    }   
    for(int i=1, m=0; i<n*n; i+=3, m++)
    {
        y[m] = aux2[i];
        s[m] = aux2[i+1];
    }

    bubbleSort(n,p,y,s);
    
    copiavS();
    
    fifo(n,y,s);
    
    resetaS();

    srt(n,y,s);

    resetaS();

    prio(n,p,y,s);

    resetaS();

    rrq(n,y,s);

    delete p;
    delete y;
    delete s;

    cout<<"O arquivo 'saida.txt' foi gerado!\n";

    return 0;

}
int tamArquivo(string nomeTXT)
{
    ifstream arq;
    string line;
    int count = -1;

    arq.open(nomeTXT, ios::out );

    if(arq.is_open()){

            //Rodar enquanto todo o arquivo não for lido(eof).
            while(!arq.eof()) {
                
                //Quebra cada linha do arq e armazena numa string.
                getline(arq,line);
                count++;
            }
        }

    arq.close();
    
    return count;
}
void entradaArquivo(string nomeTXT){

    ifstream arquivo;
    string linha;

    //Abri o arquivo.
    arquivo.open(nomeTXT, ios::out );
        
        //Verifica se o arquivo foi aberto corretamente
        if(arquivo.is_open()){

            //Rodar enquanto todo o arquivo não for lido(eof).
            while(!arquivo.eof()){
                
                //Quebra cada linha do arq e armazena numa string.
                getline(arquivo,linha);
                quebrarLinha(linha);
            }
        }
        else
        {
            cout <<"\nO arquivo não foi aberto corretamente.\n";
        }

    arquivo.close();
}

char *convercaoStringParaChar(string linha)
{
    //As duas linhas de codigo criam uma copia da string em um *char; 
    //Pois só é possivel conveter atraves do *char.
    char * aux = (char*) calloc(linha.length()+1, sizeof(char*));
    strcpy(aux, linha.c_str());

    return aux;
}

//Quebra as linha do arquivo em outras variaveis.
void quebrarLinha(string linha)
{
    char *linhaAux;
    char *fragLinha;//*char para quebrar a linha 
    
    linhaAux = convercaoStringParaChar(linha);

    //Percorre toda a linha, ignora os espacos em branco e armazena os valores em outras variaveis.
    fragLinha = strtok(linhaAux," ");
    
    aux1[j] = atoi(fragLinha);
    j++;

    while(fragLinha != NULL)
    {
        fragLinha = strtok(NULL," ");

        //converter valores em int
        aux2[k] = atoi(fragLinha);
        k++;
    }
    
}

void copiavS()
{   
     for(int i=0; i<n; i++)
    {
        copyS[i] = s[i];
    }
} 

void resetaS()
{
    for(int i=0; i<n; i++)
    {
        s[i] = copyS[i];
    }
}