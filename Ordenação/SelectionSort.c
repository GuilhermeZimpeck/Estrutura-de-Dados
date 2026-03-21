#include <stdio.h>
#define MAX 100

void selectionSort(int vetor[],int n){
    int i, j, menor, aux;

    for(i = 0 ; i < n-1 ; i++)
    {
        menor = i;
        for(j = i+1 ; j < n ; j++)
        {
            if(vetor[menor]>vetor[j])
                menor = j;
        }
        aux = vetor[i];
        vetor[i] = vetor[menor];
        vetor[menor] = aux;
    }
    i = 0;
    while(i<n){
    printf("%d  |  ",vetor[i]);
    i++;
    }
}


int main(){
    int i = 0;
    int qtd, vetor[MAX];
    
    printf("digite a quantidade de numeros: ");
    scanf("%d",&qtd);
    while(i<qtd){
    printf("digite o %d numero: ", i+1);
    scanf("%d",&vetor[i]);
    i++;
    }
    selectionSort(vetor,qtd);
    return 0;
}
