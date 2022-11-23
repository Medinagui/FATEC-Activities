/*5- Desenvolva um programa em C++ que adiciona 20 itens Node programa “Lista Duplamente Encadeada 
com  Funções”  desenvolvido  em  sala  de  aula.  Use  valores  inteiros  iniciados  com  1  em  ordem 
crescente. Adicione nesse programa uma chamada para uma função que seja responsável por realizar 
a busca binária de itens nessa lista. Implemente essa função. */

#include <iostream>
#include <windows.h>

using namespace std;

struct Node
{
    char item;
    Node *prox;
    Node *ant;
};

class ListaDE
{
    private: 
        Node *primeiro, *ultimo;
    public:
        ListaDE() 
        {
            primeiro = ultimo = NULL; 
        }

        bool vazio()
        { 
            return(primeiro==NULL); 
        }
        
        double item_frente() 
        { 
            return primeiro->item;   
        }

        double item_fim()    
        { 
            return ultimo->item;  
        } 

        void adiciona(double valor)
        {
            Node *novo = new Node();
            novo->item= valor;
            novo->prox= NULL;
            if(vazio())
            {
                novo->ant= NULL;
                primeiro = novo;
            }
            else
            {
                novo->ant = ultimo;
                ultimo->prox= novo;
            }
            ultimo= novo;
        }

        void insere(int pos, double valor)
        {
            if(pos< 0) return; 
            Node* novo = new Node();
            novo->item = valor;
            if(pos== 0) 
            { 
                novo->prox = primeiro;
                novo->ant = NULL;
                primeiro->ant = novo;
                primeiro = novo;
                return;
            }
            Node *atual, *proximo;
            atual = primeiro;
            proximo = atual->prox;
            for(int i = 1; i < pos && atual->prox != NULL; i++)
            {
                atual= atual->prox;
                proximo = atual->prox;
            }
            novo->prox = atual->prox;
            novo->ant = atual;
            atual->prox = novo;
            if(novo->prox == NULL) ultimo= novo;
            else proximo->ant = novo;
        } 

        bool pesquisa(double chave) 
        {
            Node *atual = primeiro;
            while (atual!= NULL) 
            {  
                if(atual->item == chave) return true;
                atual = atual->prox;
            }
            return false;
        }

        void imprime_inicio() 
        {
            Node *atual= primeiro;
            while (atual!= NULL) 
            {   
                cout << "{" << atual->item<< "} ";
                atual = atual->prox;
            }
            cout << endl;
        }

        void imprime_fim()
        {
            Node *atual = ultimo;
            while (atual!= NULL) 
            {   
                cout << "{" << atual->item<< "} ";
                atual = atual->ant;
            }
            cout << endl;
        }
        
        void apaga(double valor)
        {  
            Node *atual, *anterior, *proximo;
            anterior = NULL;
            atual = primeiro; 
            proximo = atual->prox; 
            while (atual!= NULL) 
            { 
                if (atual->item == valor) break;
                anterior = atual;
                atual = atual->prox;
                if (atual != NULL) proximo = atual->prox;
            }   
            if (atual == NULL) return; 
            if (atual == primeiro && atual == ultimo) primeiro = ultimo = NULL;
            else if (atual == primeiro) 
            { 
                primeiro = primeiro->prox;
                primeiro->ant = NULL;
            }
            else if (atual->prox== NULL) 
            { 
                ultimo = anterior;
                ultimo->prox = NULL;
            }
            else
            { 
                anterior->prox = proximo;
                proximo->ant = anterior;
            }
        }
};  

int main(int argc, char const *argv[])
{
    
    return 0;
}
