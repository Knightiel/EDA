#include <stdio.h>
#include <stdlib.h>

//Deque (double ended queue) din�mico 

typedef struct {
    struct No* anterior; 
    struct No* proximo; 
    int v; 
} No;

typedef struct {
    No* cabeca;
    No* cauda;
} Deque;

Deque* cria(){
    Deque* d = malloc(sizeof(Deque));
    d->cabeca = d->cauda = NULL; 
    return d;
}

int vazio(Deque* d){
     return d->cabeca == NULL && d->cauda == NULL;
}

void adicionaInicio(Deque* d, int v){
    No* no = malloc(sizeof(No));

    no->v = v;
    no->anterior = NULL;
    no->proximo = d->cabeca;
    d->cabeca = no;
    if (d->cauda == NULL) {
        d->cauda = d->cabeca;
    }
}

void adicionaFim(Deque* deque, int v){
    No* no = malloc(sizeof(No));
    no->v = v;
    no->proximo = NULL;

    if (deque->cauda != NULL) {
        deque->cauda->proximo = no;
    }

    deque->cauda = no;
    
    if (deque->cabeca == NULL) {
        deque->cabeca = no;
    }
}

int retiraInicio(Deque* deque){
    int v;
    if (vazio(deque)) {
        printf("Deque vazio");
        exit(-1);
    } else {
        No* no = deque->cabeca;
        v = no->v; 
        deque->cabeca = no->proximo;
        if (deque->cabeca == NULL) {
        deque->cauda = NULL;
        }
        free(no);
    }   
    return v;
}

int retiraFim(Deque* d){
    int v;
    if (vazio(d)) {
        printf("Deque vazio");
        exit(-1);
    }
    v = d->cauda->v;
    No* no = d->cauda->anterior;
    free(d->cauda);
    d->cauda = no;
    if (d->cauda == NULL) {
        d->cabeca = NULL;
    }
    return v;
}

void percorre(Deque *d){
    No* no = d->cabeca;
    while (no != NULL) {
        printf("%d ", no->v);
        no = no->proximo;
    }
}

int percorreDiferente(Deque *d, int num){
    No* no = d->cabeca;
    while (no != NULL) {
        if(no->v == num){
        	return 1;
		}
        no = no->proximo;
    }
    return 0;
}

/*int remover(Deque* d, int v) {
    No* no = d->cabeca;
    while (no != NULL) {
        if (no->v == v) {
            if (no->anterior == NULL) {
                retiraInicio(d);
            } else if (no->proximo == NULL) {
                retiraFim(d);
            } else {
                no->anterior->proximo = no->proximo;
                no->proximo->anterior = no->anterior;
                free(no);
            }
            return 1;
        }
        no = no->proximo;
    }
    return 0;
}*/

int main(){
    Deque *deque = cria();
    int i;
    for(i=0; i<20; i++){
        adicionaFim(deque, i);
    }
    int num;
    percorre(deque);
    printf("\n\n");
    printf("Digite o valor que deseja remover: ");
    scanf("%i", &num);
    int ehPossivelRemover = percorreDiferente(deque, num);
  //  printf("\n\n");
  //  percorre(deque);
    printf("\n\n");
    if(ehPossivelRemover == 1){
    	printf("True");
	}else{
		printf("False");
	}
    return 0;
}