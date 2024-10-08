#include <stdlib.h>
#include <stdio.h>

void heapify(int v[], int n, int i) {

    // Initialize largest as root
    int largest = i; 

    // left index = 2*i + 1
    int l = 2 * i + 1; 

    // right index = 2*i + 2
    int r = 2 * i + 2;

    // If left child is larger than root
    if (l < n && v[l] > v[largest]) {
        largest = l;
    }

    // If right child is larger than largest so far
    if (r < n && v[r] > v[largest]) {
        largest = r;
    }

    // If largest is not root
    if (largest != i) {
        int temp = v[i];
        v[i] = v[largest];
        v[largest] = temp;

        // Recursively heapify the affected sub-tree
        heapify(v, n, largest);
    }
}

void heapsort(int v[], int n) {
    // Cria o heap máximo a partir dos nós não folha (n / 2 - 1)
    // Valores maiores que n / 2 - 1 são nós folha
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(v, n, i);
    }

    // Recria o heap máximo reduzindo o tamanho da heap a cada iteração (heap parcial)
    for (int i = n - 1; i > 0; i--) {
        swap(v, 0, i); // Troca o primeiro valor (maior) pelo último da heap parcial

        heapify(v, i, 0); // Atualiza o heap máximo parcial
    }
}

// // Main function to do heap sort
// void heapSort(int arr[], int n) {

//     // Build heap (rearrange array)
//     for (int i = n / 2 - 1; i >= 0; i--) {
//         heapify(arr, n, i);
//     }

//     // One by one extract an element from heap
//     for (int i = n - 1; i > 0; i--) {

//         // Move current root to end
//         int temp = arr[0]; 
//         arr[0] = arr[i];
//         arr[i] = temp;

//         // Call max heapify on the reduced heap
//         heapify(arr, i, 0);
//     }
// }

int main(){
    int n = 10;
    int vet[] = {2, 6, 1, 7, 10, 9, 5, 4, 3, 2, 0};
    heapsort(vet, n);
    for(int i=0; i<n; i++){
        printf("%i ", i);
    }
    return 0;
}