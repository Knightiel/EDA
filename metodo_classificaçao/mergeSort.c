#include <stdio.h>
#include <stdlib.h>

//*********************TOP-DOWN***************************

void merge(int v[], int inicio, int meio, int fim) {
    int aux[fim - inicio + 1];
    int i = inicio, j = meio + 1, k = 0;
    while (i <= meio && j <= fim) { // Intercala
        // (*c)+=2;
        aux[k++] = v[i] <= v[j] ? v[i++] : v[j++];
    }
    while (i <= meio){
        // (*c)++;
        aux[k++] = v[i++]; // Copia o resto do subvetor que não terminou
    } 
    while (j <= fim){
        // (*c)++;
        aux[k++] = v[j++]; // Copia o resto do subvetor que não terminou
    } 
    for (i = inicio, k = 0; i <= fim; i++, k++) { // Copia de volta para o vetor original
        v[i] = aux[k];
    }
}

void mergesort(int v[], int n) {
    _mergesort(v, 0, n - 1);
}

void _mergesort(int v[], int inicio, int fim) {
    int meio = (inicio + fim) / 2;

    if (inicio < fim) {
        _mergesort(v, inicio, meio); // Dividir
        _mergesort(v, meio + 1, fim);

        merge(v, inicio, meio, fim); // Conquistar
    }
}

//*********************************************************

//********************BOTTOM-UP****************************

void mergesortBU(int v[], int n) {
    _mergesortBU(v, 0, n - 1);
}

void _mergesortBU(int v[], int inicio, int fim) {
    int i, meio;
    for (meio = 1; meio < fim - inicio + 1; meio = 2 * meio) { // Determina o meio de cada iteração
        for (i = inicio; i <= fim - meio; i += 2 * meio) { // Determina o inicio/fim de cada iteração
            int j = (i + (2 * meio)) - 1;
            if (j > fim) j = fim;

            merge(v, i, i + meio - 1, j); // Intercala
        }
    }
}

//*********************************************************

int main(){
    int n = 1000;

}