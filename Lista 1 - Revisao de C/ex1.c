#include <stdio.h>
#include <stdlib.h>

void insert_values(int *v, int n){
    int i;
    int value;
    for(i=0; i<n; i++){
        printf("Digite um valor para inserir no vetor: ");
        scanf("%i", &value);
        v[i] = value;
    }
}

int verify_sum(int *v, int k, int n){
    int i=0, j=0, value=0, boolean=0;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            value = v[i] + v[j];
            if(value = k){
                boolean = 1;
            }
        }
    }
    return boolean;
}

int main(){
	int *vetor;
	int n;
	int k = 0;
    int result;
	
	printf("Digite o tamanho do vetor: ");
	scanf("%d", &n);
    vetor = (int *) malloc(n * sizeof(int));
	insert_values(vetor, n);
    printf("Digite um número aleatório: ");
    scanf("%d", &k);
    result = verify_sum(vetor, k, n);
    printf("%d", result);
    if(result==1){
        printf("O valor corresponde a soma de dois valores encontrados no vetor!");
    }else{
        printf("O valor nao foi encontrado em nenhuma soma de pares.");
    }

    return 0;
}