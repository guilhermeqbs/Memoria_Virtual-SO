#include <iostream>

using namespace std;

void setValores(int *memoriaFisica, int tamFisica, int *e);
int tamMemoriaFisica(int p, int n);
void divisaoEndereco(int *e, int tam, int p);

int* alocamentoMemoria(int *e, int p, int n, int tam)
{
    int tamFisica;
    int *memoriaFisica;
    int primeiro;

    tamFisica = tamMemoriaFisica(p,n);
    memoriaFisica = new int (tamFisica);

    setValores(memoriaFisica, tamFisica, e);
    
    //primeiro;

    for(int j=tamFisica, i=0; j <tam; j++, i++) //percorre os dois vetores
    {
        if(memoriaFisica[i] != e[j]) //quando tiver uma troca
        { 
            memoriaFisica[i] = e[j];//se o 'i' mudar mesmo sem entrar aqui
        }

        if(i==tamFisica-1)
        {
            i=-1;
        }
        //arrumar saida
    }

    return memoriaFisica;
}

void divisaoEndereco(int *e, int tam, int p) //define o novo end da mem fís referente ao end da mem virt
{
    for(int i=0; i<tam; i++)
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