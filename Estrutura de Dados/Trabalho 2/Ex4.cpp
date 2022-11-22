/*Desenvolva um programa em C que leia do usuário 10 caracteres de uma lista simplesmente
encadeada e os imprima na tela juntamente com:
a) O endereço de cada elemento da lista e
b) O endereço do ponteiro de próximo.
Responda: Como você interpretou o resultado impresso na tela.*/

/*CÓDIGO CRIADO POR GUILHERME MEDINA PARA A AULA DE ESTRUTURA DE DADOS DA FATEC TAUBATÉ*/

#include <iostream>
#include <windows.h>

using namespace std;

struct Node
{
    double item;
    Node *prox;
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

        double item_frente()
        {
            return primeiro->item;
        }

        void adiciona(double valor)
        {
            Node *lista = new Node();
            lista->item = valor;
            lista->prox = NULL;
            if(vazio()) primeiro = lista;
            else ultimo->prox = lista;
            ultimo = lista;
        }

        void insere(int pos, double valor)
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


        bool pesquisa(double chave)
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
                cout << " " << atual->item;
                atual = atual->prox;
            }
            cout << endl;
        }

        void apaga(double valor)
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

int main(int argc, char const *argv[])
{
    ListaSE l;
    cout << ">>> Adicionando 2.4, 1.3, -7 no fim\n";
    l.adiciona(2.4); l.adiciona(1.3); l.adiciona(-7); 
    cout << " Imprimindo Lista: "; 
    l.imprime();
    cout << ">>> Inserindo -5.5 na posicao 1\n";
    l.insere(1,-5.5);
    cout << " Imprimindo Lista: "; 
    l.imprime();cout << ">>> Inserindo 32 na posicao 3\n";
    l.insere(3,32);cout << " Imprimindo Lista: "; 
    l.imprime();
    cout << ">>> Removendo 1.3\n";
    l.apaga(1.3);
    cout << ">>> Removendo todos itens do inicio ao fim:\n";
    while (!l.vazio()) 
    { 
        cout << " Removido {"<< l.item_frente() << "}\n";
        l.apaga(l.item_frente());
    }
    return 0;
}

