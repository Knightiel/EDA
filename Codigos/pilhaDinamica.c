#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    struct no* anterior;
    int valor;
} No;

typedef struct {
    No* topo;
} Pilha;

Pilha* criar() {
    Pilha* pilha = malloc(sizeof(Pilha));
    pilha->topo = NULL;
    return pilha;
}

int vazia(Pilha* pilha) {
    return pilha->topo == NULL;
}

void push(Pilha* pilha, int valor) {
    No* no = malloc(sizeof(No));
    no->anterior = pilha->topo;
    no->valor = valor;
    
    pilha->topo = no;
}

int peek(Pilha* pilha) {
    if (!vazia(pilha)) {
        return pilha->topo->valor;
    } else {
        printf("Pilha vazia");
        exit(0);
    }
}

int pop(Pilha* pilha) {
    if (!vazia(pilha)) {
        No* no = pilha->topo;
        int valor = no->valor;
        pilha->topo = no->anterior;
        free(no);

        return valor;
    } else {
        printf("Pilha vazia");
        exit(0);
    }
}

int main() {
    int n;

    printf("Informe a quantidade de elementos: ");
    scanf("%d", &n);

    Pilha* pilha = criar();

    printf("Empilhando....\n");
    
    for (int i = 1; i <= n; i++) {
        push(pilha, i);
        printf("%d\n", peek(pilha));
    }

    printf("Desempilhando....\n");

    while (!vazia(pilha)) {
        printf("%d\n", pop(pilha));
    }
}