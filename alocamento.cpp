#include <iostream>

using namespace std;

int contador=0;

void setValores(int *memoriaFisica, int tamFisica, int *e);
int tamMemoriaFisica(int p, int n);
void divisaoEndereco(int *e, int tam, int p);
bool checkMF(int *memoriaFisica, int tamFisica,int valor);
int trocas();

int* alocamentoMemoria(int *e, int p, int n, int tam)
{
    int tamFisica;
    int *memoriaFisica;
    int primeiro;

    tamFisica = tamMemoriaFisica(p,n);
    memoriaFisica = new int (tamFisica);

    setValores(memoriaFisica, tamFisica, e);
    
    //primeiro;

    for(int j=tamFisica, i=0; j <=tam; j++) //percorre os dois vetores
    {
        
        //Temos que olhar os 4 valores e nao so um como antes  
        if(checkMF(memoriaFisica,tamFisica,e[j]) == false) //quando tiver uma troca
        { 
            memoriaFisica[i] = e[j];//se o 'i' mudar mesmo sem entrar aqui
            i++;
            
            if(i==tamFisica)
            {
                i=0;
            }

            contador++;
        }
        //arrumar saida
    }

    return memoriaFisica;
}

void divisaoEndereco(int *e, int tam, int p) //define o novo end da mem fís referente ao end da mem virt
{
    for(int i=0; i<=tam; i++)
    {
        e[i]/=p;
    }
}

int tamMemoriaFisica(int p, int n) //define o tamanho do vetor mem.fís
{
    return n/p;
}

void setValores(int *memoriaFisica, int tamFisica, int *e)
{
    for(int i=0; i<tamFisica; i++)
    {
        memoriaFisica[i] = e[i];
    }
}

bool checkMF(int *memoriaFisica, int tamFisica, int valor)
{   
    for(int b=0; b<tamFisica;b++)
    {
        if(valor == memoriaFisica[b])
        {
            return true;
        }
    }

    return false;
}

int trocas()
{
    return contador;
}