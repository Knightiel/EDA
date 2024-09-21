#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int topo;
    int* v;
    int tamanho;
} Pilha;

Pilha* criar(int tamanho) {
    Pilha* pilha = malloc(sizeof(Pilha));
    pilha->v = malloc(sizeof(int) * tamanho);
    pilha->tamanho = tamanho;
    pilha->topo = 0;
}

int vazia(Pilha* pilha) {
    return pilha->topo == 0;
}

int cheia(Pilha* pilha) {
    return pilha->topo == pilha->tamanho;
}

int peek(Pilha* pilha) {
    if (!vazia(pilha)) {
        return pilha->v[pilha->topo - 1];
    } else {
        printf("Pilha vazia\n");
        exit(0);
    }
}

void push(Pilha* pilha, int valor) {
    if (!cheia(pilha)) {
        pilha->v[pilha->topo++] = valor;
    } else {
        printf("Pilha cheia\n");
        exit(0);
    }
}

int pop(Pilha* pilha) {
    if (!vazia(pilha)) {
        return pilha->v[--pilha->topo];
    }
}

int main() {
    Pilha* pilha = criar(10);
    int valor = 1;
    
    while (!cheia(pilha)) {
        push(pilha, valor++);
    }

    while (!vazia(pilha)) {
        printf("%d\n", pop(pilha));
    }
}