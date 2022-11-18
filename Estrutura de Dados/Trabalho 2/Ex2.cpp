/*Construa  um  programa  que  leia  10  valores  do  tipo  int  e  
empilhe-os  conforme  forem  pares  ou impares na pilha1 e pilha2, respectivamente. 
No final desempilhe os valores de cada pilha.*/

#include <iostream>
#include <windows.h>

using namespace std;

class Pilha{
    
    private:
        int *itens;
        int topo, tam_max;

    public:
        Pilha(int n) 
        {
            itens = new int[n];
            tam_max = n;
            topo = 0;
        }
    
    bool empty()
    {
        return (topo == 0);
    }

    bool full()
    {
        return (topo == tam_max);
    }

    int size()
    {
        return topo;
    }

    void push(int valor) 
    {
        if (full())
        {
            cout << "\n\n- PILHA CHEIA. ITEM NÃO ADICIONADO - \n\n";
            return;
        }

        itens[topo] = valor;
        topo++;
    }

    void pop()
    {
        if(empty())
        {
            cout << "\n\n- ATENÇÃO, PILHA VAZIA -\n\n";
            return;
        }
        topo--;
    }

    int top()
    {
        if(!empty()) return itens[topo - 1];
    }
};

int main(int argc, char const *argv[])
{
    Pilha pilhaImpar = 10, pilhaPar = 10;
    
    int valor, sizePar, sizeImpar;

    system("cls");
    cout << "----- PILHA DE PARES E IMPARES -----\n";

    for (int i = 0; i < 10; i++)
    {
        cout << "\nInforme o " << i + 1 << " valor: ";
        cin >> valor;
        if (valor % 2 == 0)
        {
            pilhaPar.push(valor);
        }
        else
        {
            pilhaImpar.push(valor);
        }
    }
    
    system("cls");

    /*Desempilhando:*/

    sizePar = pilhaPar.size();
    sizeImpar = pilhaImpar.size();

    if (pilhaPar.empty())
    {
       cout << "\nPilha de Pares esta vazia.";
    }
    else
    {
        cout << "\nPilha de Pares: ";
        for (int i = 0; i < sizePar; i++)
        {
            cout << pilhaPar.top() << " ";
            pilhaPar.pop();
        }
    }

    if (pilhaImpar.empty())
    {
       cout << "\nPilha de Impares esta vazia.";
    }
    else
    {
        cout << "\nPilha de Impares: ";
        for (int i = 0; i < sizeImpar; i++)
        {
            cout << pilhaImpar.top() << " ";
            pilhaImpar.pop();
        }
    }   

    return 0;
}
