#include <stdio.h>
#define MAX 100

void bubbleSort(int vetor[],int n){
    int i, j, aux;

    for(i = 0 ; i < n ; i++)
    {
        for(j = i+1 ; j < n ; j++)
        {
            if(vetor[i]>vetor[j])
            {
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            }
        }
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
    bubbleSort(vetor,qtd);
    return 0;
}
