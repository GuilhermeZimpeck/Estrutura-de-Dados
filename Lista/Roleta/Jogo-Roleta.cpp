#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

// Estrutura do nó
struct No {
    int valor;
    No* prox;
};

int ordemRoleta[37] = {
    0, 32, 15, 19, 4, 21, 2, 25, 17, 34,
    6, 27, 13, 36, 11, 30, 8, 23, 10, 5,
    24, 16, 33, 1, 20, 14, 31, 9, 22, 18,
    29, 7, 28, 12, 35, 3, 26
};

// Inserir no final
void inserir(No*& inicio, int valor) {

    No* novo = new No;
    novo->valor = valor;

    if (inicio == NULL) {
        inicio = novo;
        novo->prox = inicio;
        return;
    }

    No* temp = inicio;

    while (temp->prox != inicio) {
        temp = temp->prox;
    }

    temp->prox = novo;
    novo->prox = inicio;
}

// Animação da roleta
No* roleta(No* atual) {

    int passos = rand() % 60 + 20;

    for (int i = 0; i < passos; i++) {

        system("cls");

        cout << endl;
        cout << "Girando a roleta..." << endl << endl;

        cout << "==================" << endl;
        cout << "       ";
        cout << atual->valor ;
        cout << endl;
        cout << "==================" << endl;

        atual = atual->prox;

        // vai desacelerando
        Sleep(50 + i * 5);
    }

    return atual;
}

int main() {

    srand(time(0));

    No* lista = NULL;
    int op, aposta, cor, resultado;

    for (int i = 0; i < 37; i++) {
        inserir(lista, ordemRoleta[i]);
    }

    cout << "Voce quer apostar em cor (0) ou numero (1)? ";
    cin >> op;

    if (op == 0) {

        cout << "Digite (0) para vermelho ou (1) para preto: ";
        cin >> cor;

    } else {

        cout << "Digite o numero: ";
        cin >> aposta;
    }

    No* atual = lista;

    atual = roleta(atual);

    cout << endl;
    cout << "Resultado: " << atual->valor - 1;

        resultado = atual->valor % 2;

        if (resultado == 0)
            cout << " VERMELHO" << endl;
        else
            cout << " PRETO" << endl;

    // Verificar vitória
    if (op == 0) {

        if (atual->valor == 0)
            cout << endl << "VOCE PERDEU :( ";
        else if ((atual->valor % 2) == cor)
            cout << "!!!! VOCE GANHOU :D !!!!";
        else
            cout << endl << "VOCE PERDEU :( ";

    } else {

        if (atual->valor == aposta)
            cout << "!!!! VOCE GANHOU :D !!!!";
        else
            cout << endl << "VOCE PERDEU :( ";
    }
    system("pause");
    return 0;
}
