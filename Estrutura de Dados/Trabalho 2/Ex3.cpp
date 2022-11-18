/*Desenvolva  um  programa  em  C  que  leia n  caracteres  digitados  pelo  usuário,
até  que  o  mesmo pressione a tecla ENTER, e os atribua a uma fila conforme forem 
letras maiúsculas e minúsculas, fila 1 e fila 2, respectivamente. 
No final retire o conteúdo de cada fila mostrando-os na tela.*/

#include <iostream>
#include <windows.h>

using namespace std;

class Fila{
    private:
        double *itens;
        int fim, tam_max;
    public:
    Fila (int n)
    {
        itens = new double[n];
        tam_max = n;
        fim = 0;    
    }

    void enqueue(double valor)
    {
        if (full())
        {
            cout << "- FILA CHEIA - ITEM NAO ADICIONADO -";
            return;
        }
        else
        {
            itens[fim] = valor;
            fim++;
        }
    }

    void dequeue()
    {
        if(empty())
        {
            cout << "- ATENCAO - PILHA VAZIA -";
        }
        else
        {
            for(int i = 0; i < (fim - 1); i++)
            {
                itens[i] = itens[i + 1];
            }
            fim--;
            itens[fim] = 0;
        }
    }

    double front()
    {
        if(!empty())
        {
            return itens[0];
        }
    }

    bool empty()
    {
        return(fim == 0);
    }

    bool full()
    {
        return (fim == tam_max);
    }

    int size()
    {
        return fim;
    }

int main(int argc, char const *argv[])
{
    return 0;
}

};