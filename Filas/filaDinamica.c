#include <stdlib.h>
#include <stdio.h>

typedef struct {
 struct No* proximo; //ponteiro para o próximo nó
 int v; //valor do nó
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

void adiciona(Fila* fila, int v){
    No* no = malloc(sizeof(No));
    no->v = v;
    no->proximo = NULL;

    if (fila->cauda != NULL) {
        fila->cauda->proximo = no;
    }

    fila->cauda = no;
    
    if (fila->cabeca == NULL) {
        fila->cabeca = no;
    }
}

int vazia(Fila* f){
     return f->cabeca == NULL && f->cauda == NULL;
}

int retira(Fila* f){
    int v;
    if (vazia(f)) {
        printf("Fila vazia");
        exit(-1);
    } else {
        No* no = f->cabeca;
        v = no->v; //recupera valor do início
        f->cabeca = no->proximo;
        if (f->cabeca == NULL) {
        f->cauda = NULL;
        }
        free(no);
    }
    return v;
}

void limpa(Fila* f){
    while (!vazia(f)) {
    retira(f);
    }
    free(f);
}

void percorre(Fila *f){
    No* no = f->cabeca;
    while (no != NULL) {
        printf("%d", no->v);
        no = no->proximo;
    }
}


int main(){
    Fila *fila = cria();
    int i;
    for(i=0; i<10; i++){
        adiciona(fila, i);
    }
    percorre(fila);
    for(i; i>10; i--){
        retira(fila);
    }
    percorre(fila);
    
    return 0;
}