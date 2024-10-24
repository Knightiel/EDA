#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int populaVetor(int v[], int n){
    int i;
    for(i=0; i< n; i++){
        v[i] = i;
    }
}

void bubblesort(int v[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (v[i] > v[j]) { // realiza a troca (swap)
                int aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
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

int pesquisaBinaria(int chave, int v[], int n) {
    int inicio = 0, meio;
    int fim = n-1;
    int cont=1;
    while (inicio <= fim) {
        cont++;
        meio = (inicio + fim) / 2;
        if (chave == v[meio]) {
            cont++;
            return cont;
        } else if (chave < v[meio]) {
            cont++;
            fim = meio - 1;
        } else {
            cont++;
            inicio = meio + 1;
        }
    }
    cont++;
    return cont++; //Índice inválido
}

int main(){
    int n = 100;
    int* vetor = malloc((n + 2) * sizeof(int));
    populaVetor(vetor, n);
    bubblesort(vetor, n);

    printf("\n\nPesquisa sequencial");
    printf("\nMelhor caso: %d", pesquisaSequencial(vetor[0], vetor, n));
    printf("\nCaso medio: %d", pesquisaSequencial(rand() % n, vetor, n));
    printf("\nPior caso: %d", pesquisaSequencial(vetor[n], vetor, n));

    printf("\n\nPesquisa sequencial com sentinela");
    printf("\nMelhor caso: %d", pesquisaSequencialSentinela(vetor[0], vetor, n));
    printf("\nCaso medio: %d", pesquisaSequencialSentinela(rand() % n, vetor, n));
    printf("\nPior caso: %d", pesquisaSequencialSentinela(vetor[n], vetor, n));

    printf("\n\nPesquisa binaria");
    printf("\nMelhor caso: %d", pesquisaBinaria(vetor[49], vetor, n));
    printf("\nCaso medio: %d", pesquisaBinaria(rand() % n, vetor, n));
    printf("\nPior caso: %d", pesquisaBinaria(vetor[n], vetor, n));


    return 0;
}