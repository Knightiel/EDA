// Faça um programa que leia dois conjuntos de números inteiros de tamanho n e m,
// respectivamente, e os armazene em duas filas estáticas. Em seguida, o programa deve
// gerar uma fila dinâmica contendo a interseção das duas filas estáticas.

#include <stdio.h>
#include <stdlib.h>

//Estática

typedef struct {
 int cabeca, cauda; //posição atual da cabeça e da cauda da fila
 int v[]; //vetor contendo o conteúdo da fila
} Fila;

Fila* cria(int tamanho){
    Fila* f = malloc(sizeof(Fila));
    f->v[tamanho];
    f->cabeca = f->cauda = -1; //inicializa a posição atual com -1
    return f;
}

int vazia(Fila* f){
    return f->cabeca == -1 && f->cauda == -1;
}

int cheia(Fila* f, int tamanho){
    return (f->cauda + 1) % tamanho == f->cabeca;
}

void adiciona(Fila* f, int valor, int tamanho){
    if (cheia(f, tamanho)) {
        printf("Capacidade máxima da fila foi alcançada");
        exit(-1);
    } else {
        f->cauda = (f->cauda + 1) % tamanho;
        f->v[f->cauda] = valor; //insere elemento na próxima posição livre

        if (f->cabeca == -1) {
            f->cabeca = f->cauda;
        }
    }
}

// int retira(Fila* f){
//     int v;
//     if (vazia(f)) {
//         printf("Fila vazia");
//         exit(-1);
//     } else {
//         v = f->v[f->cabeca]; //recupera valor da cabeça da fila
//         if (f->cabeca == f->cauda)
//             f->cabeca = f->cauda = -1;
//         else
//             f->cabeca = (f->cabeca + 1) % MAX;
//     }
//     return v;
// }

// void limpa(Fila* f){
//     if (f != NULL) {
//         free(f);
//     }

//     f = NULL;
// }

// void percorre(Fila* f){
//     for (int i = f->cabeca; i != f->cauda; i = (i + 1) % MAX) {
//         printf("%d", f->v[i]);
//     }
// }

//Dinamica

typedef struct no{
    struct no* proximo;
    int v;
}No;

typedef struct {
    No* cabeca;
    No* cauda;
}FilaDinamica;

FilaDinamica* criar(){
    FilaDinamica* fila = malloc(sizeof(fila));
    fila->cabeca = NULL;
    fila->cauda = NULL;
    return fila;
}

int vazia(FilaDinamica *fila){
    return fila->cabeca == NULL && fila->cauda == NULL;
}

void adicionar(FilaDinamica *fila, int valor){
    No* no = malloc(sizeof(No));
    no->v = valor;
    no->proximo = NULL;
    if(vazia(fila)){
        fila->cabeca = no;
    }else{
        fila->cauda->proximo = (struct no*) no;
    }
    fila->cauda = no;
}

void remover(FilaDinamica *fila){
    if(!vazia(fila)){
        No* no = fila->cabeca;
        int valor = no->v;
        fila->cabeca = fila->cabeca->proximo;
        if(fila->cabeca == NULL){
            fila->cauda = NULL;
        }
        free(no);
        return valor;
    }else{
        printf("Fila vazia");
        exit(0);
    }
}

int main(){
    int n, m;
    printf("Digite o tamanho do conjunto N");
    scanf("%i", &n);
    printf("Digite o tamanho do conjunto M");
    scanf("%i", &m);
    for(int i=0; i<n; i++){
    }
    Fila *fila = criar();
    return 0;
}