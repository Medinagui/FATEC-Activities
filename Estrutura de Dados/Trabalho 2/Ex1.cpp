/*Faça um menu iterativo com o usuário para chamada 
das funções de um programa que simule uma pilha de floats.

Implemente no menu: 

Caso 1: Inserir itens: Verificação antes da chamada da função se o tamanho da pilha é menor que 
o tamanho máximo ajustado ao vetor. 

Caso 2 e 4: Remover e Imprimir Item: Verificação antes da chamada da função se a pilha está vazia. */


/*CÓDIGO CRIADO POR GUILHERME MEDINA PARA A AULA DE ESTRUTURA DE DADOS DA FATEC TAUBATÉ*/

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

    int opcao;
    float valor;
    
    Pilha pilha1 = 10;

    while (true)
    
    {
        
        system("cls");
        imprimeMenu();
        cin >> opcao;

        while (opcao < 0 || opcao > 4)
        {
            system("cls");
            cout << "Opcao invalida, insira um numero entre 0 e 4\n\n";
            imprimeMenu();
            cin >> opcao;
        }
        

        switch (opcao)
        {
        case 0:
            return 0;
            break;
        case 1:
            system("cls");
            cout << "INSERINDO ITEM\n\nIndique o valor deseja inserir na pilha: ";
            cin >> valor;
            pilha1.push(valor);
            cout << "Item inserido!\n\n";
            system("pause");
            break;            
        case 2:
            system("cls");
            cout << "REMOVENDO ITEM\n\nO valor do topo foi removido da pilha.\n\n";
            pilha1.pop();   
            system("pause");     
            break;
        case 3:
            system("cls");
            cout << "IMPRIMINDO TAMANHO\n\nA pilha possui " << pilha1.size() << " itens.\n\n";
            system("pause");
            break;                    
        case 4:
            system("cls");
            cout << "IMPRIMINDO ITEM TOPO\n\nO item no topo da pilha é " << pilha1.top() << "\n\n"; 
            system("pause");      
            break;
        }
    }
}
