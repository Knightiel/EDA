#include <stdio.h>
#include <stdlib.h>

#define MAX 10
typedef struct {
 int cabeca, cauda; //posição atual da cabeça e da cauda da fila
 int v[MAX]; //vetor contendo o conteúdo da fila
} Fila;

// Fila* cria(){
//     Fila* f = malloc(sizeof(Fila));
//     f->cabeca = f->cauda = -1; //inicializa a posição atual com -1
//     return f;
// }

int vazia(Fila* f){
    return f->cabeca == -1 && f->cauda == -1;
}

int cheia(Fila* f){
    return (f->cauda + 1) % MAX == f->cabeca;
}

void adiciona(Fila* f, int valor){
    if (cheia(f)) {
        printf("Capacidade máxima da fila foi alcançada");
        exit(-1);
    } else {
        f->cauda = (f->cauda + 1) % MAX;
        f->v[f->cauda] = valor; //insere elemento na próxima posição livre

        if (f->cabeca == -1) {
            f->cabeca = f->cauda;
        }
    }
}

int retira(Fila* f){
    int v;
    if (vazia(f)) {
        printf("Fila vazia");
        exit(-1);
    } else {
        v = f->v[f->cabeca]; //recupera valor da cabeça da fila
        if (f->cabeca == f->cauda)
            f->cabeca = f->cauda = -1;
        else
            f->cabeca = (f->cabeca + 1) % MAX;
    }
    return v;
}

void limpa(Fila* f){
    if (f != NULL) {
        free(f);
    }

    f = NULL;
}

void percorre(Fila* f){
    for (int i = f->cabeca; i != f->cauda; i = (i + 1) % MAX) {
        printf("%d", f->v[i]);
    }
}

int main(){
    Fila* f = malloc(sizeof(Fila));
    f->cabeca = f->cauda = -1; //inicializa a posição atual com -1
    for(int i=0;i<MAX; i++){
        adiciona(f, i);
    }
    percorre(f);
    return 0;
}