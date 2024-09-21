//Altere o programa do exercício 4 para listar a quantidade total de números exclusivos
//como resultado da interseção.


#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* vetor;
    int cabeca;
    int cauda;
    int capacidade;
} FilaEstatica;

typedef struct no {
    int valor;
    struct no* proximo;
} No;

typedef struct {
    No* cabeca;
    No* cauda;
} FilaDinamica;

FilaEstatica* criarFilaEstatica(int capacidade) {
    FilaEstatica* fila = malloc(sizeof(FilaEstatica));
    fila->vetor = malloc(sizeof(int) *capacidade);
    fila->capacidade = capacidade;
    fila->cabeca = -1;
    fila->cauda = -1;

    return fila;
}

FilaDinamica* criarFilaDinamica() {
    FilaDinamica* fila = malloc(sizeof(FilaDinamica));
    fila->cabeca = NULL;
    fila->cauda = NULL;

    return fila;
}

int filaEstaticaVazia(FilaEstatica* fila) {
    return fila->cabeca == -1 && fila->cauda == -1;
}

int filaDinamicaVazia(FilaDinamica* fila) {
    return fila->cabeca == NULL && fila->cauda == NULL;
}

int filaEstaticaCheia(FilaEstatica* fila) {
    return (fila->cauda + 1) % fila->capacidade == fila->cabeca;
}

void adicionarFilaEstatica(FilaEstatica* fila, int valor) {
    if (filaEstaticaCheia(fila)) {
        printf("Fila cheia");
        exit(0);
    }

    fila->cauda = (fila->cauda + 1) % fila->capacidade;
    
    if (fila->cabeca == -1) {
        fila->cabeca = fila->cauda;
    }
    
    fila->vetor[fila->cauda] = valor;
}

void adicionarFilaDinamica(FilaDinamica* fila, int valor) {
    No* no = fila->cabeca;
    
    while (no != NULL) {
        if (no->valor == valor) {
            return;
        }
        no = no->proximo;
    }
    
    no = malloc(sizeof(No));
    no->valor = valor;
    no->proximo = NULL;

    if (fila->cauda == NULL) {
        fila->cauda = no;
        fila->cabeca = no;
    } else {
        fila->cauda->proximo = no;
    }

    fila->cauda = no;
}

int removerFilaEstatica(FilaEstatica* fila) {
    if (filaEstaticaVazia(fila)) {
        printf("Fila vazia");
        exit(0);
    }

    int valor = fila->vetor[fila->cabeca];
    
    if (fila->cabeca == fila->cauda) {
        fila->cabeca = -1;
        fila->cauda = -1;
    } else {
        fila->cabeca = (fila->cabeca + 1) % fila->capacidade;
    }

    return valor;
}

int filaEstaticaExiste(FilaEstatica* fila, int valor) {
    if (filaEstaticaVazia(fila)) {
        printf("Fila vazia");
        exit(0);
    }
    
    for (int i = fila->cabeca; i != fila->cauda; i = (i + 1) % fila->capacidade) {
        if (fila->vetor[i] == valor) {
            return 1;
        }
    }

    if (fila->vetor[fila->cauda] == valor) {
        return 1;
    }

    return 0;
}

void percorrerFilaDinamica(FilaDinamica* fila) {
    No* no = fila->cabeca;

    while (no != NULL) {
        printf("%d\n", no->valor);
        no = no->proximo;
    }
}

int main() {
    int m, n;

    printf("Informe o tamanho da primeira fila: ");
    scanf("%d", &m);

    FilaEstatica* a = criarFilaEstatica(m);

    for (int i = 0; i < m; i++) {
        int valor;
        printf("Informe o %d valor: ", i + 1);
        scanf("%d", &valor);
        adicionarFilaEstatica(a, valor);
    }

    printf("Informe o tamanho da segunda fila: ");
    scanf("%d", &n);

    FilaEstatica* b = criarFilaEstatica(n);

    for (int i = 0; i < n; i++) {
        int valor;
        printf("Informe o %d valor: ", i + 1);
        scanf("%d", &valor);
        adicionarFilaEstatica(b, valor);
    }

    FilaDinamica* c = criarFilaDinamica();

    while (!filaEstaticaVazia(a)) {
        int valor = removerFilaEstatica(a);

        if (filaEstaticaExiste(b, valor)) {
            adicionarFilaDinamica(c, valor);
        }
    }

    percorrerFilaDinamica(c);
}