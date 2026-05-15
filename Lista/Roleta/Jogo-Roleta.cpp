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

// Ordem real da roleta
int ordemRoleta[37] = {
    0, 32, 15, 19, 4, 21, 2, 25, 17, 34,
    6, 27, 13, 36, 11, 30, 8, 23, 10, 5,
    24, 16, 33, 1, 20, 14, 31, 9, 22, 18,
    29, 7, 28, 12, 35, 3, 26
};

// Função para verificar cor real da roleta
// 0 = vermelho
// 1 = preto
int corRoleta(int numero) {

    int vermelhos[] = {
        1,3,5,7,9,12,14,16,18,
        19,21,23,25,27,30,32,34,36
    };

    if (numero == 0)
        return -1;

    for (int i = 0; i < 18; i++) {
        if (numero == vermelhos[i])
            return 0;
    }

    return 1;
}

// Inserir no final da lista circular
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

        // anda primeiro
        atual = atual->prox;

        cout << endl;
        cout << "Girando a roleta..." << endl << endl;

        cout << "==================" << endl;
        cout << "       " << atual->valor << endl;
        cout << "==================" << endl;

        // desaceleração
        Sleep(50 + i * 5);
    }

    return atual;
}

int main() {

    srand(time(0));

    No* lista = NULL;

    int op;
    int aposta;
    int cor;

    // Criar roleta circular
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
    cout << "Resultado: " << atual->valor;

    int resultadoCor = corRoleta(atual->valor);

    if (resultadoCor == 0)
        cout << " VERMELHO" << endl;
    else if (resultadoCor == 1)
        cout << " PRETO" << endl;
    else
        cout << " VERDE" << endl;

    // Verificar vitória
    if (op == 0) {

        if (resultadoCor == -1) {

            cout << endl << "VOCE PERDEU :( ";

        } else if (resultadoCor == cor) {

            cout << endl << "!!!! VOCE GANHOU :D !!!!";

        } else {

            cout << endl << "VOCE PERDEU :( ";
        }

    } else {

        if (atual->valor == aposta) {

            cout << endl << "!!!! VOCE GANHOU :D !!!!";

        } else {

            cout << endl << "VOCE PERDEU :( ";
        }
    }

    // Liberar memória
    No* temp = lista->prox;

    while (temp != lista) {

        No* apagar = temp;
        temp = temp->prox;
        delete apagar;
    }

    delete lista;

    system("pause");
    return 0;
}
