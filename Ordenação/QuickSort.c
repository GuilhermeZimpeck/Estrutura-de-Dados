#include <stdio.h>
#define MAX 100

void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(int A[], int inicio , int fim)
{
    int i, j, chave;
    if(fim - inicio< 2){
        if(fim - inicio == 1){
            if(A[inicio] > A[fim]){
                troca(&A[inicio], &A[fim]);
            }
        }
    }
    else
    {
        i = inicio;
        j = fim;
        chave = A[inicio];
        while(j > i)
        {
            i++;
            while(A[i] < chave)
            {
                i++;
            }
            while(A[j] > chave)
            {
                j--;
            }
            if(j > i)
            {
                troca(&A[i] , &A[j]);
            }
        }
        troca(&A[inicio],&A[j]);
        quickSort(A,inicio,j-1);
        quickSort(A,j+1,fim);
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
    
    quickSort(vetor, 0 , qtd-1);
    
    i = 0;
    while(i<qtd)
    {
    printf("%d  |  ",vetor[i]);
    i++;
    }
    
    return 0;
}
