// Faça um programa que leia uma palavra e retorne true se a palavra é um palíndromo,
// caso contrário false.
// ○ Exemplo 1: dado a palavra ARARA, a saída esperada é true
// ○ Exemplo 2: dado a palavra AMOR, a saída esperada é false


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int topo;
    int max;
    char* v;
} Pilha;

Pilha* criar(int n) {
    Pilha* pilha = malloc(sizeof(Pilha));
    pilha->v = malloc(sizeof(char) * n);
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

void empilhar(Pilha* pilha, char valor) {
    if (!cheia(pilha)) {
        pilha->v[pilha->topo++] = valor;
    }
}

char desempilhar(Pilha* pilha) {
    if (!vazia(pilha)) {
        return pilha->v[--pilha->topo];
    }
    
    return '\0';
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
    char palavra[20];

    printf("Informe uma palavra: ");
    scanf("%s", palavra);

    int n = strlen(palavra);

    Pilha *pilha = criar(n);
    
    for (int i = 0; i < n; i++) {
        empilhar(pilha, palavra[i]);
    }
    
    for (int i = 0; i < n; i++) {
        char ch = desempilhar(pilha);

        if (palavra[i] != ch) {
            printf("Nao palindromo!\n");
            return 0;
        }
    }

    printf("Palindromo!\n");
}