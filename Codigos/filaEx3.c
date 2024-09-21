/*
Faça um programa que leia um conjunto de números
inteiros de tamanho n e armazene estes valores em
uma fila estática. Em seguida, o programa deve ler
um novo valor k e retornar true caso k exista na 
fila, caso contrário false.

Exemplo: dados os valores [1,2,3,4,5]e k = 3, 
a saída esperada é true
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* v;
    int cabeca, cauda;
    int capacidade;
} Fila;

Fila* criar(int capacidade) {
    Fila* fila = malloc(sizeof(Fila));

    fila->v = malloc(capacidade * sizeof(int));
    fila->cabeca = -1;
    fila->cauda = -1;
    fila->capacidade = capacidade;

    return fila;
}

int vazia(Fila* fila) {
    return fila->cabeca == -1 && fila->cauda == -1;
}

int cheia(Fila* fila) {
    return (fila->cauda + 1) % fila->capacidade == fila->cabeca;
}

void adicionar(Fila* fila, int valor) {
    if (!cheia(fila)) {
        fila->cauda = (fila->cauda + 1) % fila->capacidade;
        fila->v[fila->cauda] = valor;

        if (fila->cabeca == -1) {
            fila->cabeca = fila->cauda;
        }
    }
}

int remover(Fila* fila) {
    if (!vazia(fila)) {
        int valor = fila->v[fila->cabeca];
        
        if (fila->cabeca == fila->cauda) {
            fila->cabeca = -1;
            fila->cauda = -1;
        } else {
            fila->cabeca = (fila->cabeca + 1) % fila->capacidade;
        }

        return valor;
    }

    return 0;
}

void percorrer(Fila* fila) {
    if (!vazia(fila)) {
        for (int i = fila->cabeca; i != fila->cauda; i = (i + 1) % fila->capacidade) {
            printf("%d\n", fila->v[i]);
        }

        printf("%d\n", fila->v[fila->cauda]);
    }
}

int localizar(Fila* fila, int valor) {
    if (!vazia(fila)) {
        for (int i = fila->cabeca; i != fila->cauda; i = (i + 1) % fila->capacidade) {
            if (fila->v[i] == valor) {
                return 1;
            }
        }

        if (fila->v[fila->cauda] == valor) {
            return 1;
        }
    }

    return 0;
}

int main() {
    int n, k;

    printf("Informe n: ");
    scanf("%d", &n);
    
    Fila* fila = criar(n);

    for (int i = 1; i <= n; i++) {
        int valor;

        printf("Informe o %d valor: ", i);
        scanf("%d", &valor);

        adicionar(fila, valor);
    }

    percorrer(fila);

    printf("Informe k: ");
    scanf("%d", &k);

    printf(localizar(fila, k) ? "true\n" : "false\n");
}