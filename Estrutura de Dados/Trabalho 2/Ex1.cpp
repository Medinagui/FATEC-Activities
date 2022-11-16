/*Faça um menu iterativo com o usuário para chamada 
das funções de um programa que simule uma pilha de floats.

Implemente no menu: 

Caso 1: Inserir itens: Verificação antes da chamada da função se o tamanho da pilha é menor que 
o tamanho máximo ajustado ao vetor. 

Caso 2 e 4: Remover e Imprimir Item: Verificação antes da chamada da função se a pilha está vazia. */

#include <iostream>
#include <windows.h>

using namespace std;

class Pilha{
    
    private:
        float *itens;
        int topo, tam_max;

    public:
        Pilha(int n) 
        {
            itens = new float[n];
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

    void push(float valor) 
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

    float top()
    {
        if(!empty()) return itens[topo - 1];
    }
};


void imprimeMenu()
{
    cout << "PROGRAMA PILHA\n\n";
    cout << "[ 0 ] - Sair";
    cout << "\n[ 1 ] - Inserir Itens";
    cout << "\n[ 2 ] - Remover Itens";
    cout << "\n[ 3 ] - Imprimir Tamanho";
    cout << "\n[ 4 ] - Imprimir Item Topo\n\n";
}

int main(int argc, char const *argv[])
{
    system("pause");
    return 0;
}
