//Lista de Exercicios - Árvores Binarias de Busca
//1. Escreva uma função que conta o número de nós de uma árvore binária.

//2. Escreva uma função que conta o número de nos não-folha de uma árvore binária.

//3. Escreva uma função que conta o número de folhas de uma árvore binária.

//4. Escreva uma função que calcula a altura de uma árvore binária.

//5. Escreva uma função que encontra o valor máximo em uma árvore de busca binária.

//6. Escreva uma função não-recursiva que retorne o menor valor de uma  árvore binária de busca.

//7.Escreva funções não recursivas para realizar os 3 tipos de percurso na árvore binária
//(dica: use uma pilha):
//(a) pré-ordem
//(b) em-ordem
//(c) pós-ordem

#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int info;
    struct node *direita, *esquerda;
}node;
struct node* novoNo(int x){
    struct  node* tmp = malloc(sizeof(node));
    tmp->info = x;
    tmp->direita = tmp->esquerda = NULL;
    return tmp;
}
node raiz = NULL;

struct node* insere(struct  node* raiz, int x){

    if(raiz == NULL){
        return novoNo(x);
    }
    if (x < raiz->info){
        raiz->esquerda = insert(raiz->esquerda, x);
    }
    else if (x > raiz->info){
        raiz->direita = insert(raiz->direita,x)
    }
    return raiz;
}
int numero_de_nos(struct node*raiz){
    
}

int numero_de_nos_folha(node raiz){


}
int numero_de_nos_nao_folha(node raiz){
    

}
int max_valor(){

}
int menor_valor(){


}
int preordem(){

}
int emordem(){

}
int posordem(){

}
int altura(){

}

int main(){

}