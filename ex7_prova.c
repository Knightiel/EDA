#include <stdio.h>
#include <stdlib.h>

typedef struct contato{
    char nome[50];
    char telefone[20];
}Contato;

typedef struct {
 struct No* proximo; //ponteiro para o próximo nó
 Contato v; //valor do nó
} No;

typedef struct {
 No* cabeca; //ponteiro para o início da fila
 No* cauda; //ponteiro para o fim da fila
} Fila;

Fila* cria(){
    Fila* fila = malloc(sizeof(Fila));
    fila->cabeca = fila->cauda = NULL; //inicializa os ponteiros com nulo
    return fila;
}

int vazia(Fila* f){
     return f->cabeca == NULL && f->cauda == NULL;
}

void percorre(Fila *f){
    No* no = f->cabeca;
    while (no != NULL) {
        printf("%d", no->v);
        no = no->proximo;
    }
}

void adicionaContato(Fila* fila, Contato contato) {
    No* no = malloc(sizeof(No));
    no->v = contato; 
    no->proximo = NULL;

    if (fila->cauda != NULL) {
        fila->cauda->proximo = no;
    }

    fila->cauda = no;
    
    if (fila->cabeca == NULL) {
        fila->cabeca = no;
    }
}

//fazer pilha para edição


int main(){
    
    return 0;
}