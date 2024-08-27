#include <stdio.h>
#include <stdlib.h>

typedef struct elemento {
    struct elemento* anterior; //ponteiro para o elemento anterior
    int valor; //valor do elemento
} Elemento;

typedef struct {
    Elemento* topo; //ponteiro para o topo da pilha
} Pilha;

//cria uma nova pilha
Pilha* criar(){
    Pilha* pilha = malloc(sizeof(Pilha));
    pilha->topo = NULL; //inicializa o topo da pilha com nulo
    return pilha;
}

//verifica se a pilha esta vazia
int vazia(Pilha* pilha){
    return pilha->topo == NULL;
}

//insere um valor novo na pilha
void empilhar(Pilha* pilha, int valor){ //push
    Elemento* elemento = malloc(sizeof(Elemento));
    elemento->valor = valor;
    elemento->anterior = pilha->topo;
    pilha->topo = elemento;
}

//remove elemento do topo da pilha (pop)
char desempilhar(Pilha* pilha){  
    char v[45];
    if (vazia(pilha)) {
        printf("Pilha vazia");
        exit(-1);
    } else {
        Elemento* elemento = pilha->topo; //pilha->topo->valor
        v = elemento->valor; //recupera valor do topo
        pilha->topo = elemento->anterior;
        free(elemento); //libera memória orfã
    }
    return v;
}

int espiar(Pilha* pilha){
    if(!vazia(pilha)){
        return pilha->topo->valor;
    }else{
        printf("Pilha vazia!");
        exit(-1);
    }
}

//libera memoria da pilha
void limpa(Pilha *p){
    while (p->topo != NULL) {
        Elemento *elemento = p->topo;
        p->topo = elemento->anterior;
        free(elemento);
    }
    free(p);
}

//visitar todos os elementos da pilha
void percorre(Pilha *p){
    while (vazia(p)) {
        int v = desempilhar(p);
        printf(" %d", v);
    }
}

int main(){
    Pilha *pilha = criar();
    int booleana = 0;
    printf("Digite ( ou ). Digite 0 para PARAR: \n");
    do{
        char letras[45];
        scanf("%c", letras);
        if(letras == "0"){
            booleana = 1;
        }else{
            empilhar(pilha, letras);
        }
    }while(booleana == 0);

    char parenteses[45];

    while(!vazia(pilha)){
        parenteses = desempilhar(pilhas);
        if(parenteses == "(" || parenteses == ")"){
            booleana = 1;
        }else{
            booleana = 0;

        }
    }
    // printf("Empilha: ");
    // for(int i=0; i<=n; i++){
    //     empilhar(pilha, i);
    //     printf(" %d", espiar(pilha));
    // }
    // printf("\nDesempilha: ");
    // while(!vazia(pilha)){
    //     printf(" %d", desempilhar(pilha));
    // }
    return 0;
}