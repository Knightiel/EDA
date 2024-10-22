#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int populaVetor(int v[], int n){
    int i;
    for(i=0; i< n; i++){
        v[i] = i;
    }
}

int pesquisaSequencial(int chave, int v[], int n) {
    int i;
    int cont = 1;
    for (i = 0; i < n; i++) {
        cont++;
        if (v[i] == chave) {
            return cont; //sucesso
        }
        cont++;
    }
    return cont; //índice inválido (fracasso)
}

int pesquisaSequencialSentinela(int chave, int v[], int n) {
    int i = 0;
    int cont = 1;
    v[n] = chave; //A última posição do vetor possui o sentinela
    while (v[i] != chave) {
        i++;
        cont++;
    }
    cont++;
    if (i < n){
        return cont;  
    }

    return cont; //Índice inválido
}


int main(){
    int n = 10;
    int* vetor = malloc((n + 2) * sizeof(int));
    populaVetor(vetor, n);

    printf("\n\nPesquisa sequencial");
    printf("\nMelhor caso: %d", pesquisaSequencial(vetor[0], vetor, n));
    printf("\nCaso medio: %d", pesquisaSequencial(rand() % n, vetor, n));
    printf("\nPior caso: %d", pesquisaSequencial(vetor[n], vetor, n));

    printf("\n\nPesquisa sequencial com sentinela");
    printf("\nMelhor caso: %d", pesquisaSequencialSentinela(vetor[0], vetor, n));
    printf("\nCaso medio: %d", pesquisaSequencialSentinela(rand() % n, vetor, n));
    printf("\nPior caso: %d", pesquisaSequencialSentinela(vetor[n], vetor, n));
    return 0;
}