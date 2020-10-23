#include <iostream>
#include <fstream>
#include <string>
#include <locale.h>
#include <stdio.h>
#include <string.h>

#include "alocamento.cpp"
#include "bubbleSort.cpp"
#include "escrita.cpp"

int m, n, p, *e;
int tam, count=0, cont;
int *aux1, *aux2, k=0, j=-1, *mf;

using namespace std;

void entradaArquivo(string nomeTXT);
void quebrarLinha(string linha);//Quebra a linha do arquivo em interos
char *convercaoStringParaChar(string linha);
int tamArquivo(string nomeTXT);
void insercaoValores();

//realiza a leitura do arquivo de entrada com os dados dos processos
int main(){
    
    setlocale(LC_ALL,NULL);
   
    string nomeTXT = "entrada.txt";

    cout<<"\nO arquivo 'entrada.txt' vai ser lido...\n\n";
    
    tam = tamArquivo(nomeTXT) - 2;

    //alocacao dos vetores
    aux1 = new int[tam+2];
    e = new int[tam];
    aux2 = new int[2];

    entradaArquivo(nomeTXT);

    insercaoValores();
    
    divisaoEndereco(e,tam,p);

    mf = alocamentoMemoria(e,p,n,tam);

    bubbleSort(tamMemoriaFisica(p,n),mf);

    cont = trocas();
    
    for(int i=0; i<4; i++)
    {
        cout << mf[i] << endl;
    }
    
    cout <<endl <<cont <<endl;
    saidaArquivo(cont,mf,(n/p));
    cout<<"O arquivo 'saida.txt' foi gerado!\n";

    
    return 0;

}
int tamArquivo(string nomeTXT)
{
    ifstream arq;
    string line;
    int contador = -1;

    arq.open(nomeTXT, ios::out );

    if(arq.is_open()){

            //Rodar enquanto todo o arquivo não for lido(eof).
            while(!arq.eof()) {
                
                //Quebra cada linha do arq e armazena numa string.
                getline(arq,line);
                contador++;
            }
        }

    arq.close();
    
    return contador;
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

void insercaoValores()
{
    for(int i=0; i<tam+1; i++) //insere os endereços de mem no vetor
    {
        e[i] = aux1[i+1];
    }

    m = aux1[-1];
    n = aux2[0];
    p = aux2[1];
}