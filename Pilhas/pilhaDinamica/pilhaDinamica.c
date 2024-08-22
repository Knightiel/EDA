#include <stdio.h>
#include <stdlib.h>

typedef struct {
    struct No* anterior; //ponteiro para o nó anterior
    int v; //valor do nó
} No;

typedef struct {
    No* topo; //ponteiro para o topo da pilha
} Pilha;

//cria uma nova pilha
Pilha* cria(){
    Pilha *p = malloc(sizeof(Pilha));
    p->topo = NULL; //inicializa o topo da pilha com nulo
    return p;
}

//insere um valor novo na pilha
void push(Pilha *p, int v){
    No *no = malloc(sizeof(No));
    no->v = v;
    no->anterior = p->topo;
    p->topo = no;
}

//verifica se a pilha esta vazia
int vazia(Pilha *p){
    return p->topo == NULL;
}

//remove elemento do topo da pilha
int pop(Pilha *p){
    int v;
    if (vazia(p)) {
        printf("Pilha vazia");
        exit(-1);
    } else {
        No* no = p->topo;
        v = no->v; //recupera valor do topo
        p->topo = no->anterior;
        free(no);
    }
    return v;
}

//libera memoria da pilha
void limpa(Pilha *p){
    while (p->topo != NULL) {
        No *no = p->topo;
        p->topo = no->anterior;
        free(no);
    }
    free(p);
}

//visitar todos os elementos da pilha
void percorre(Pilha *p){
    while (vazia(p)) {
        int v = pop(p);
        printf("%d", v);
    }
}

int main(){

    return 0;
}