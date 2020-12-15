

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100 



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

struct node* insere(struct  node* raiz, int x){

    if(raiz == NULL){
        return novoNo(x);
    }
    if (x < raiz->info){
        raiz->esquerda = insere(raiz->esquerda, x);
    }
    else if (x > raiz->info){
        raiz->direita = insere(raiz->direita,x);
    }
    return raiz;
}
// Numero total de nos
int numero_de_nos(struct node* raiz){
  int n = 1;
 
	if(raiz==NULL)
		return 0;
	if(raiz->esquerda!=NULL)
	{
		n+=numero_de_nos(raiz->esquerda);
	}
	if(raiz->direita!=NULL)
	{
		
		n+=numero_de_nos(raiz->direita);
	}
  return n;
}

// Numero de nos filho
int numero_de_nos_folha(struct node *raiz){
  int n = 0;
  if(raiz->direita == NULL &  raiz->esquerda == NULL){
    n = 1;
  }else{
    if (raiz->esquerda != NULL){
      n += numero_de_nos_folha(raiz->esquerda);
    }
    if(raiz->direita != NULL){
      n += numero_de_nos_folha(raiz->direita);
    }
  }
  return n;
}

// Numero de nos pai

int numero_de_nos_nao_folha(struct node *raiz){
  int n = 0;
  if(raiz->esquerda != NULL || raiz->direita != NULL){
    n = 1;
    if(raiz->esquerda != NULL){
      n += numero_de_nos_nao_folha(raiz->esquerda);
    }
    if(raiz->direita != NULL){
      n += numero_de_nos_nao_folha(raiz->direita);
    }
  }
      return  n;
}

// Deterina altura (profundidade) da arvore
int altura(struct node* raiz)  
{  
    if (raiz == NULL)  
        return 0;  
    else
    {  
    
        int alturaSubArvoreEsquerda = altura(raiz->esquerda);  
        int alturaSubarvoreDireita = altura(raiz->direita);  
      
        if (alturaSubArvoreEsquerda > alturaSubarvoreDireita)  
            return(alturaSubArvoreEsquerda + 1);  
        else return(alturaSubarvoreDireita + 1);  
    }  
}  
// Funcao que calcula maior valor utilizando recursao
int max(struct node * raiz){
    int n = 0;
    if(raiz->direita==NULL){
        return (raiz->info);
    }
    else{
       n = max(raiz->direita);
    }
    return n; 
}
// Funcao que calcula menor valor sem o uso de recursao
int min(struct node * raiz){
    struct node *tmp = raiz;
    while(tmp->esquerda != NULL){
      tmp= tmp->esquerda;
    }
    return (tmp->info);
}

// Pilha para operar trajetos sem recursao
typedef struct pilhaNode 
{ 
  struct node *t; 
  struct pilhaNode *prox; 
}pilhaNode;



void push(struct pilhaNode** topo, struct node *t){ 
  struct pilhaNode* tmp = malloc(sizeof(pilhaNode)); 
  if(tmp == NULL){ 
     getchar(); 
     exit(0); 
  }             
  tmp->t  = t;   
  tmp->prox = (*topo);    
  (*topo) = tmp; 
} 
  

bool pilhaVazia(struct pilhaNode *topo) 
{ 
   return (topo == NULL)? 1 : 0; 
}    
  
struct node *pop(struct pilhaNode** topo_ref) 
{ 
  struct node *res; 
  struct pilhaNode *topo; 
  
  if(pilhaVazia(*topo_ref)) 
  { 
     getchar(); 
     exit(0); 
  } 
  else
  { 
     topo = *topo_ref;
     res = topo->t; 
     *topo_ref = topo->prox; 
     free(topo); 
     return res; 
  } 
} 

// trajeto em ordem sem utilizar recursao
void emOrdem(struct node *raiz) 
{ 
  struct node *atual = raiz; 
  struct pilhaNode *p = NULL;  
  bool flag = 0; 
  
  while (!flag) 
  { 
    if(atual !=  NULL) 
    { 
      push(&p, atual);                                                
      atual = atual->esquerda;   
    } 
    else 
    { 
      if (!pilhaVazia(p)) 
      { 
        atual = pop(&p); 
        printf("%d ", atual->info); 

        atual = atual->direita; 
      } 
      else
        flag = 1;  
    } 
  }   
} 
// trajeto em ordem sem utilizar recursao

 void preOrdem(struct node *raiz)
 {
   node *save[100];
   int topo = 0;
   if (raiz == NULL){
     return;
   }
   save[topo++] = raiz;
   while (topo != 0)
   {
     raiz = save[--topo];
 
     printf("%d ", raiz->info);
 
     if (raiz->direita != NULL)
       save[topo++] = raiz->direita;
     if (raiz->esquerda != NULL)
       save[topo++] = raiz->esquerda;
   }
 }


typedef struct pilha{ 
    int tamanho; 
    int topo; 
    struct node** v; 
}pilha; 

  
struct pilha* criaPilha(int x) 
{ 
    struct pilha* p = (struct pilha*)malloc(sizeof(struct pilha)); 
    p->tamanho = x; 
    p->topo = -1; 
    p->v = (struct node**)malloc(p->tamanho * sizeof(struct pilha*)); 
    return p; 
} 
  
int pilhaCheia(struct pilha* p){ 
    return p->topo - 1 == p->tamanho; 
} 
  
int pilhaVazia2(struct pilha* p){ 
    return p->topo == -1; 
} 
  
void push2(struct pilha* p, struct node* raiz) 
{ 
    if (pilhaCheia(p)) 
        return; 
    p->v[++p->topo] = raiz; 
} 
  
struct node* pop2(struct pilha* p) 
{ 
    if (pilhaVazia2(p)) 
        return NULL; 
    return p->v[p->topo--]; 
} 
  
void posOrdem(struct node* raiz) 
{ 
    if (raiz == NULL) 
        return; 
  
  
    struct pilha* p1 = criaPilha(MAX); 
    struct pilha* p2 = criaPilha(MAX); 
  
    push2(p1, raiz); 
    struct node* node; 
  
    while (!pilhaVazia2(p1)) { 
        node = pop2(p1); 
        push2(p2, node); 

        if (node->esquerda) 
            push2(p1, node->esquerda); 
        if (node->direita) 
            push2(p1, node->direita); 
    } 
  
    while (!pilhaVazia2(p2)) { 
        node = pop2(p2); 
        printf("%d ", node->info); 
    } 
} 





int main(){
  node *raiz = NULL;
  raiz = insere(raiz,20);
  insere(raiz,5);
  insere(raiz,1);
  insere(raiz,15);
  insere(raiz,9);
  insere(raiz,7);
  insere(raiz,12);
  insere(raiz,30);
  insere(raiz,25);
  insere(raiz,40);
  insere(raiz, 45);
  insere(raiz, 42);
  printf("\n numero de nos na BST: %d", numero_de_nos(raiz));
  printf("\n numero de nos folha na BST: %d", numero_de_nos_folha(raiz));
  printf("\n numero de nos nao  folha na BST: %d", numero_de_nos_nao_folha(raiz));
  printf("\n Altura da  BST: %d", altura(raiz));
  printf("\n Elemento max na BST: %d", max(raiz));
  printf("\n Elemento min na BST %d", min(raiz));
  printf("\n Percurso em Ordem na BST: ");
  emOrdem(raiz);
  printf("\n Percurso em Pre-Ordem na BST: ");
  preOrdem(raiz);
  printf("\n Percurso em Pos-Ordem na BST: ");
  posOrdem(raiz);

  /*
                   20
                 /    \
                /      \
               5       30
             /   \     /\
            /     \   /  \
           1      15 25  40
                /          \
               /            \
              9             45
            /   \          /
           /     \        /
          7      12      42
    */

}