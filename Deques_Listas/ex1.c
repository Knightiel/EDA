#include <stdio.h>
#include <stdlib.h>

//Deque (double ended queue) dinâmico 

typedef struct {
    No* anterior; //ponteiro para o nó anterior do deque
    No* proximo; //ponteiro para o próximo nó do deque
    int v; //conteúdo do nó
} No;

typedef struct {
    No* cabeca;
    No* cauda;
} Deque;

Deque* cria(){
    Deque* d = malloc(sizeof(Deque));
    d->cabeca = d->cauda = NULL; //inicia a cabeça e cauda do deque
    return d;
}

int vazio(Deque* d){
     return d->cabeca == NULL && d->cauda == NULL;
}

void adicionaInicio(Deque* d, int v){
    No* no = malloc(sizeof(No));

    no->v = v;
    no->anterior = NULL;
    no->proximo = d->cabeca;
    d->cabeca = no;
    if (d->cauda == NULL) {
        d->cauda = d->cabeca;
    }
}

void adicionaFim(Deque* deque, int v){
    No* no = malloc(sizeof(No));
    no->v = v;
    no->proximo = NULL;

    if (deque->cauda != NULL) {
        deque->cauda->proximo = no;
    }

    deque->cauda = no;
    
    if (deque->cabeca == NULL) {
        deque->cabeca = no;
    }
}

int retiraInicio(Deque* deque){
    int v;
    if (vazio(deque)) {
        printf("Fila vazia");
        exit(-1);
    } else {
        No* no = deque->cabeca;
        v = no->v; //recupera valor do início
        deque->cabeca = no->proximo;
        if (deque->cabeca == NULL) {
        deque->cauda = NULL;
        }
        free(no);
    }   
    return v;
}

int retiraFim(Deque* d){
    int v;
    if (vazio(d)) {
        printf("Deque vazio");
        exit(-1);
    }
    v = d->cauda->v;
    No* no = d->cauda->anterior;
    free(d->cauda);
    d->cauda = no;
    if (d->cauda == NULL) {
        d->cabeca = NULL;
    }
    return v;
}

void percorre(Deque *d){
    No* no = d->cabeca;
    while (no != NULL) {
        printf("%d", no->v);
        no = no->proximo;
    }
}

int main(){
    Deque *deque = cria();
    int n, num;
    printf("Digite a quantidade de números que serão digitados: ");
    scanf("%i", &n);
    for(int i=0; i<n; i++){
        scanf("%i", &num);
        adicionaFim(deque, num);
    }
    percorre(deque);
    return 0;
}