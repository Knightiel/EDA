#include <stdio.h>
#include <stdlib.h>

void mover(int disco, int origem, int destino){
    printf("Mover disco %d do pino %d para o pino %d\n", disco, origem, destino);
}

void hanoi(int n, int o /*Origem*/, int d /*Destino*/, int a /*Auxiliar*/){
    if(n>0){
        hanoi(n-1, o, a, d);
        mover(n, o, d);
        hanoi(n-1, a, d, o);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    hanoi(n, 1, 2, 3);
    return 0;
}