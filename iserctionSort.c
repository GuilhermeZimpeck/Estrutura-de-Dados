#include <stdio.h>
#define MAX 100

void inserctionSort(int vetor[],int n){
    int i, j, aux;

    for(i = 1 ; i < n; i++)
    {
        aux = vetor[i];
        j = i - 1;
        while(j >= 0 && aux < vetor[j])
        {
            vetor[j+1] = vetor[j];
            j--;
        }
        vetor[j+1] = aux;
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
    inserctionSort(vetor,qtd);
    return 0;
}