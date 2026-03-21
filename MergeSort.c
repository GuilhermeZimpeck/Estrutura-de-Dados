#include <stdio.h>
#define MAX 100

void intercala(int A[], int inicio, int fim, int meio)
{
    int i, aux[MAX], posLivre = inicio, inicioA1 = inicio, inicioA2 = meio + 1;
    while(inicioA1 <= meio && inicioA2 <= fim)
    {
        if(A[inicioA1] > A[inicioA2])
        {
            aux[posLivre] = A[inicioA2];
            inicioA2++;
        }
        else
        {
            aux[posLivre] = A[inicioA1];
            inicioA1++;
        }
        posLivre++;
    }
    for(i = inicioA1; i <= meio ; i++)
    {
        aux[posLivre] = A[i];
        posLivre++;
    }
    for(i = inicioA2 ; i <= fim ; i++)
    {
        aux[posLivre] = A[i];
        posLivre++;
    }
    for(i = inicio ; i <= fim ; i++)
        A[i] = aux[i];
}

void mergeSort(int A[],int inicio,int fim)
{
    int meio;
    if(inicio < fim)
    {
        meio = (inicio + fim)/2;
        mergeSort(A, inicio , meio);
        mergeSort(A, meio + 1 , fim);
        intercala(A , inicio , fim , meio);
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
    
    mergeSort(vetor, 0 , qtd-1);
    
    i = 0;
    while(i<qtd)
    {
    printf("%d  |  ",vetor[i]);
    i++;
    }
    
    return 0;
}