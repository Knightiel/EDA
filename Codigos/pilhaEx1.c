// Faça um programa que leia um conjunto de números inteiros de tamanho n e armazene
// estes valores em uma pilha estática. Em seguida, deve ser exibido todos os valores do
// conjunto em ordem inversa à sequência inserção.
// ○ Exemplo: dado [10,15,3,7], a saída deve ser 7, 6, 15, 10

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
    
    while (!cheia(pilha)) {
        int valor;
        
        printf("Informe um valor: ");
        scanf("%d", &valor);
        empilhar(pilha, valor);
    }
    
    while(!vazia(pilha)){
        printf("%d ", desempilhar(pilha)); 
    }

    printf("\n");
}