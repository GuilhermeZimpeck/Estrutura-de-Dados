#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX 52
#define COL 8
#define FREE 4
#define FUND 4

typedef struct {
    int valor;
    char naipe;
} Carta;

typedef struct {
    Carta cartas[MAX];
    int topo;
} Pilha;

//PILHA 
void init(Pilha *p) 
{ 
    p->topo = -1; 
}

int vazia(Pilha *p) 
{ 
    return p->topo == -1; 
}

Carta topo(Pilha *p) {
    if (!vazia(p)) return p->cartas[p->topo];
    Carta c = {0, 'X'};
    return c;
}

void push(Pilha *p, Carta c) {
    if (p->topo < MAX - 1)
        p->cartas[++p->topo] = c;
}

Carta pop(Pilha *p) {
    if (!vazia(p))
        return p->cartas[p->topo--];
    Carta c = {0, 'X'};
    return c;
}

//UTIL
int cor(Carta c) {
    if (c.naipe == 'C' || c.naipe == 'P')
        return 0; // preto
    return 1; // vermelho
}

//CARTA GRANDE
void printCartaLinha(Carta c, int linha) {
    char *valores[] = {"", "A","2","3","4","5","6","7","8","9","10","J","Q","K"};
    char corLetra = (cor(c) == 0) ? 'P' : 'V';

    if (c.valor == 0) {
        printf("        ");
        return;
    }

    char valorStr[3];
    sprintf(valorStr, "%s", valores[c.valor]);

    switch (linha) {
        case 0: printf("+-----+ "); break;
        case 1: printf("|  %-2s | ", valorStr); break;
        case 2: printf("|  %c  | ", c.naipe); break;
        case 3: printf("|  %c  | ", corLetra); break;
        case 4: printf("+-----+ "); break;
    }
}

//BARALHO
void criarBaralho(Carta baralho[]) {
    char naipes[] = {'C','O','E','P'};
    int k = 0;

    for (int i = 0; i < 4; i++)
        for (int v = 1; v <= 13; v++)
            baralho[k++] = (Carta){v, naipes[i]};
}

void embaralhar(Carta b[]) {
    for (int i = 0; i < 52; i++) {
        int j = rand() % 52;
        Carta t = b[i];
        b[i] = b[j];
        b[j] = t;
    }
}

//REGRAS
int podeMoverColuna(Carta a, Carta b) {
    return (cor(a) != cor(b)) && (a.valor == b.valor - 1);
}

int podeFundacao(Pilha *f, Carta c) {
    if (vazia(f)) return c.valor == 1;
    Carta t = topo(f);
    return (c.naipe == t.naipe && c.valor == t.valor + 1);
}

//DISPLAY
void mostrar(Pilha col[], Pilha free[], Pilha fund[]) {

    //FREECELLS
    printf("\n========================== FREECELL ===========================\n");
    for (int linha = 0; linha < 5; linha++) {
        for (int i = 0; i < FREE; i++)
            printCartaLinha(topo(&free[i]), linha);
        printf("\n");
    }

    //FUNDAÇÕES
    printf("\n========================== FUNDACAO ===========================\n");
    for (int linha = 0; linha < 5; linha++) {
        for (int i = 0; i < FUND; i++)
            printCartaLinha(topo(&fund[i]), linha);
        printf("\n");
    }

    //COLUNAS
    printf("\n========================== COLUNAS ============================\n");
    printf("\n|  0  | |  1  | |  2  | |  3  | |  4  | |  5  | |  6  | |  7  | \n");
    printf("\n===============================================================\n"); 

    // Descobrir a maior coluna
    int maxAltura = 0;
    for (int i = 0; i < COL; i++) {
        if (col[i].topo > maxAltura)
            maxAltura = col[i].topo;
    }

    // Para cada nível de carta (linha vertical das colunas)
    for (int nivel = 0; nivel <= maxAltura; nivel++) {

        // Cada carta tem 5 linhas
        for (int linha = 0; linha < 5; linha++) {

            // Percorre todas as colunas
            for (int c = 0; c < COL; c++) {

                if (nivel <= col[c].topo)
                    printCartaLinha(col[c].cartas[nivel], linha);
                else
                    printf("        ");
            }

            printf("\n");
        }
    }
}
//DISTRIBUIÇÃO
void distribuir(Pilha col[], Carta baralho[]) {
    int k = 0;
    for (int i = 0; i < 52; i++)
        push(&col[i % COL], baralho[k++]);
}

//MOVIMENTOS
void moverColuna(Pilha col[], int o, int d) {
    if (vazia(&col[o])) return;

    Carta c = topo(&col[o]);

    if (vazia(&col[d]) || podeMoverColuna(c, topo(&col[d])))
        push(&col[d], pop(&col[o]));
    else
        printf("Movimento invalido!\n");
}

void moverFree(Pilha col[], Pilha free[], int o, int f) {

    if (o < 0 || o >= COL || f < 0 || f >= FREE) {
        printf("Indice invalido!\n");
        return;
    }

    if (vazia(&col[o])) {
        printf("Coluna vazia!\n");
        return;
    }

    if (!vazia(&free[f])) {
        printf("Freecell ocupada!\n");
        return;
    }

    push(&free[f], pop(&col[o]));
}

void freeParaCol(Pilha free[], Pilha col[], int f, int d) {

    if (f < 0 || f >= FREE || d < 0 || d >= COL) {
        printf("Indice invalido!\n");
        return;
    }

    if (vazia(&free[f])) {
        printf("Freecell vazia!\n");
        return;
    }

    Carta c = topo(&free[f]);

    if (vazia(&col[d]) || podeMoverColuna(c, topo(&col[d]))) {
        push(&col[d], pop(&free[f]));
    } else {
        printf("Movimento invalido (regra de carta)!\n");
    }
}

void moverFund(Pilha col[], Pilha fund[], int o, int f) {
    if (vazia(&col[o])) return;

    Carta c = topo(&col[o]);

    if (podeFundacao(&fund[f], c))
        push(&fund[f], pop(&col[o]));
}

//MAIN
int main() {
    srand(time(NULL));

    Carta baralho[52];
    Pilha col[COL], free[FREE], fund[FUND];

    for (int i = 0; i < COL; i++) init(&col[i]);
    for (int i = 0; i < FREE; i++) init(&free[i]);
    for (int i = 0; i < FUND; i++) init(&fund[i]);

    criarBaralho(baralho);
    embaralhar(baralho);
    distribuir(col, baralho);

    char cmd[20];

   char linha[50];

while (1) {
    mostrar(col, free, fund);

    printf("\nComandos:\n");
    printf("move A B   -> coluna A -> B\n");
    printf("free A 0   -> coluna A -> freecell 0 \n");
    printf("back 0 A   -> freecell 0 -> coluna A\n");
    printf("stack A 0  -> coluna A -> fundacao 0 \n");
    printf("sair\n> ");

    fgets(linha, sizeof(linha), stdin);

    char cmd[20];
    int a, b;

    int lidos = sscanf(linha, "%s %d %d", cmd, &a, &b);

    if (lidos >= 1 && strcmp(cmd, "sair") == 0)
        break;

    if (lidos < 3) {
        printf("Entrada invalida!\n");
        continue;
    }

    if (strcmp(cmd, "move") == 0)
        moverColuna(col, a, b);
    else if (strcmp(cmd, "free") == 0)
        moverFree(col, free, a, b);
    else if (strcmp(cmd, "back") == 0)
        freeParaCol(free, col, a, b);
    else if (strcmp(cmd, "stack") == 0)
        moverFund(col, fund, a, b);
    else
        printf("Comando desconhecido!\n");
}
    return 0;
}
