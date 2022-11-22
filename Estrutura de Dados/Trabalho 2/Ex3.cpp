/*Desenvolva  um  programa  em  C  que  leia n  caracteres  digitados  pelo  usuário,
até  que  o  mesmo pressione a tecla ENTER, e os atribua a uma fila conforme forem 
letras maiúsculas e minúsculas, fila 1 e fila 2, respectivamente. 
No final retire o conteúdo de cada fila mostrando-os na tela.*/

/*CÓDIGO CRIADO POR GUILHERME MEDINA PARA A AULA DE ESTRUTURA DE DADOS DA FATEC TAUBATÉ*/

#include <iostream>
#include <windows.h>
#include <string.h>

using namespace std;

class Fila{
    private:
        char *itens;
        int fim, tam_max;
    public:
    Fila (int n)
    {
        itens = new char[n];
        tam_max = n;
        fim = 0;    
    }

    void enqueue(char valor)
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

    char front()
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

};

int main(int argc, char const *argv[])
{
    string entradaChar;
    int tamanhoFila;

    system("cls");
    cout << "Escreva o que quiser maiusculo e minusculo: ";
    fflush(stdin);
    cin >> entradaChar;

    Fila filaMaiusculo = entradaChar.length(), filaMinusculo = entradaChar.length();
    
    for (int i = 0; i < entradaChar.length(); i++)
    {
        if (isupper(entradaChar[i]))
        {
            filaMaiusculo.enqueue(entradaChar[i]);
        }
        else
        {
            filaMinusculo.enqueue(entradaChar[i]);
        }
    }
    
    cout << "Fila Maiusculo: ";

    tamanhoFila = filaMaiusculo.size();

    for (int i = 0; i < tamanhoFila; i++)
    {
        cout << filaMaiusculo.front();
        filaMaiusculo.dequeue();
    }   
    
    cout << "\n\nFila Minusculo: ";

    tamanhoFila = filaMinusculo.size();

    for (int i = 0; i < tamanhoFila; i++)
    {
        cout << filaMinusculo.front();
        filaMinusculo.dequeue();
    }

    return 0;
}

