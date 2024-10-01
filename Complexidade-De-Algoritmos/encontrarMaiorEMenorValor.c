#include <stdio.h>
#include <stdlib.h>

// void minmax(int v[], int n, int* min, int* max) {  //versão 2
//     *min = v[0]; // 1
//     *max = v[0]; // 1
//     for (int i = 1; i < n; i++) { // n - 1
//         if (v[i] > *max) { // n - 1
//             *max = v[i]; // A < n - 1
//         } else { // -
//             if (v[i] < *min) { // (n - 1) - A
//                 *min = v[i]; // B < (n - 1) - A
//             } // -
//         } // -
//     } // -
// }

void minmax(int v[], int n) {
    int a, b;
    int* min = v[0]; int* max = v[9];
    for (int i = 0; i < n; i+=2) { 
        if (v[i] < v[i + 1]) { 
            a = i; b = i + 1; 
        } else { 
            a = i + 1; b = i; 
        } 
        if (v[a] < *min) { 
            *min = v[a]; 
        } 
        if (v[b] > *max) { 
            *max = v[b];
        } 
    } 
}


int main(){
    int n = 10;
    int v[] = {1, 3, 532, 546, 47, 345, 32, 23, 76, 10};
    minmax(v, n);
    return 0;
}