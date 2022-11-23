/*Desenvolva um programa em C++ que leia do usuário 10 caracteres de uma lista simplesmente
encadeada e os imprima na tela juntamente com:
a) O endereço de cada elemento da lista e
b) O endereço do ponteiro de próximo.
Responda: Como você interpretou o resultado impresso na tela.*/

/*CÓDIGO CRIADO POR GUILHERME MEDINA PARA A AULA DE ESTRUTURA DE DADOS DA FATEC TAUBATÉ*/

#include <iostream>
#include <windows.h>
#include <string.h>
using namespace std;

struct Node
{
    string item;
    Node *prox;
    string *endereco = &item;
};

class ListaSE
{
    private:
        Node *primeiro;
        Node *ultimo;
    public:
        ListaSE()
        {
            primeiro = NULL;
            ultimo = NULL;
        }

        bool vazio()
        {
            return (primeiro == NULL);
        }

        string item_frente()
        {
            return primeiro->item;
        }

        void adiciona(string valor)
        {
            Node *lista = new Node();
            lista->item = valor;
            lista->prox = NULL;
            lista->endereco = lista->endereco;
            if(vazio()) primeiro = lista;
            else ultimo->prox = lista;
            ultimo = lista;
        }

        void insere(int pos, string valor)
        {
            if (pos < 0) return;

            Node *lista = new Node();
            lista->item = valor;

            if(pos == 0)
            {
                lista->prox = primeiro;
                primeiro = lista;
            }
            else
            {
                Node *atual = primeiro;
                for (int i = 0; i < pos && atual->prox != NULL; i++)
                {
                    atual = atual->prox;
                }
                lista->prox = atual->prox;
                atual->prox = lista;
                if (lista->prox == NULL) ultimo = lista;
            }
        }


        bool pesquisa(string chave)
        {
            Node *atual = primeiro;
            while (atual != NULL)
            {
                if(atual->item == chave)
                {
                    return true;
                }
                atual = atual->prox;
            }
            return false;
        }

        void imprime()
        {
            Node *atual = primeiro;
            while(atual != NULL)
            {
                cout << "\n\nITEM: " << atual->item;
                cout << "\nPOSICAO NA MEMORIA: " << atual->endereco;
                cout << "\nPROXIMO: " << atual->prox;
                atual = atual->prox;
            }
            cout << endl;
        }

        void apaga(string valor)
        {
            Node *atual, *anterior;
            atual = anterior = primeiro;
            while (atual != NULL)
            {
                if (atual->item == valor) break;
                anterior = atual;
                atual = atual->prox;
            }
            if(atual == NULL) return;
            if(atual == primeiro)
            {
                primeiro = primeiro->prox;
                anterior = NULL;
            }
            else if(atual == ultimo)
            {
                ultimo = anterior;
                ultimo->prox = NULL;
            }
            else anterior->prox = atual->prox;
            atual = NULL;
        }
};

int main(int argc, string const *argv[])
{
    ListaSE lista;
    string valor;

    system("cls");

    for (int i = 0; i < 10; i++)
    {
        cout << "\n>>> Adicione um caractere a lista: ";
        cin >> valor;
        lista.adiciona(valor);
    }
    
    lista.imprime();

    return 0;
}

