#include <stdlib.h>
#include <stdio.h>

void bubblesort(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (v[i] > v[j]) { // realiza a troca (swap)
                int aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
}

int main(){
    int n = 10;
    int vet[] = {2, 6, 1, 7, 10, 9, 5, 4, 3, 2, 0};
    bubblesort(vet, n);
    for(int i=0; i<n; i++){
        printf("%i ", i);
    }
    return 0;
}