// Faça um programa que leia um conjunto de números inteiros de tamanho n e armazene
// estes valores em uma pilha estática. Em seguida, o programa deve ler um novo valor k
// e retornar true caso k exista na pilha, caso contrário false.
// ○ Exemplo: dados os valores [1,2,3,4,5]e k = 3, a saída esperada é true

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int topo;
    int max;
    int* v;
} Pilha;

Pilha* criar(int n) {
    Pilha* pilha = malloc(sizeof(Pilha));
    pilha->v = malloc(sizeof(int) * n);
    pilha->max = n;
    pilha->topo = 0;

    return pilha;
}

int vazia(Pilha* pilha) {
    return pilha->topo == 0;
}

int cheia(Pilha* pilha) {
    return pilha->topo == pilha->max;
}

void empilhar(Pilha* pilha, int valor) {
    if (!cheia(pilha)) {
        pilha->v[pilha->topo++] = valor;
    }
}

int desempilhar(Pilha* pilha) {
    if (!vazia(pilha)) {
        return pilha->v[--pilha->topo];
    }
    
    return 0;
}

void visitar(Pilha* pilha) {
    for (int i = pilha->topo - 1; i >= 0; i--) {
        printf("Valor %d\n", pilha->v[i]);
    }
}

void limpa(Pilha* pilha) {
    free(pilha->v);
    free(pilha);
}

int main() {
    int n;

    printf("Informe o tamanho da pilha: ");
    scanf("%d",&n);

    Pilha *pilha = criar(n);
    int valor;

    while (!cheia(pilha)) {
        printf("Informe um valor: ");
        scanf("%d", &valor);
        empilhar(pilha, valor);
    }

    printf("Informe um valor para procura-lo na pilha: ");
    scanf("%d", &valor);
    
    while(!vazia(pilha)){
        if (desempilhar(pilha) == valor)  {
            printf("true\n");
            return 0;
        }
    }

    printf("false\n");
}