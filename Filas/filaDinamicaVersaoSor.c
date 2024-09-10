#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    struct no* proximo;
    int v;
}No;

typedef struct {
    No* cabeca;
    No* cauda;
}Fila;

Fila* criar(){
    Fila* fila = malloc(sizeof(fila));
    fila->cabeca = NULL;
    fila->cauda = NULL;
    return fila;
}

int vazia(Fila *fila){
    return fila->cabeca == NULL && fila->cauda == NULL;
}

void adicionar(Fila *fila, int valor){
    No* no = malloc(sizeof(No));
    no->v = valor;
    no->proximo = NULL;
    if(vazia(fila)){
        fila->cabeca = no;
    }else{
        fila->cauda->proximo = (struct no*) no;
    }
    fila->cauda = no;
}

void remover(Fila *fila){
    if(!vazia(fila)){
        No* no = fila->cabeca;
        int valor = no->v;
        fila->cabeca = fila->cabeca->proximo;
        if(fila->cabeca == NULL){
            fila->cauda = NULL;
        }
        free(no);
        return valor;
    }else{
        printf("Fila vazia");
        exit(0);
    }
}

int main(){
    Fila *fila = criar();
    return 0;
}