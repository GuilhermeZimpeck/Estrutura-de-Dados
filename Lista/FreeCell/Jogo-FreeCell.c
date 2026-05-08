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
    p->topo = -1;         //deixa a pilha com valor -1
}

int vazia(Pilha *p) 
{ 
    return p->topo == -1;        //se topo igual ao valor definido em init = vazio
}

Carta topo(Pilha *p) {
    if (!vazia(p)) 
        return p->cartas[p->topo];
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

int cor(Carta c) {
    if (c.naipe == 'E' || c.naipe == 'P')        //associa cada nipe a uma cor
        return 0;         // preto
    return 1;         // vermelho
}

void printCartaLinha(Carta c, int linha) {
    char *valores[] = {"", "A","2","3","4","5","6","7","8","9","10","J","Q","K"};        //valores possiveis
    char corLetra = (cor(c) == 0) ? 'P' : 'V';            //cor

    if (c.valor == 0) {            //caso não exista carta cria um espaço vazio
        printf("        ");
        return;
    }

    char valorStr[3];            //nipes
    sprintf(valorStr, "%s", valores[c.valor]);        //associa um nipe a determinada carta

    switch (linha) {
        case 0: printf("+-----+ "); break;            //print linha por linha baseado no for
        case 1: printf("|  %-2s | ", valorStr); break;        //print linha por linha baseado no for
        case 2: printf("|  %c  | ", c.naipe); break;        //print linha por linha baseado no for
        case 3: printf("|  %c  | ", corLetra); break;        //print linha por linha baseado no for
        case 4: printf("+-----+ "); break;        //print linha por linha baseado no for
    }
}

//BARALHO
void criarBaralho(Carta baralho[]) {
    char naipes[] = {'C','O','E','P'};        //define os quatro nipes
    int k = 0;
    int i, v;
    
    for (i = 0; i < 4; i++)        //percorre os nipes
        for ( v = 1; v <= 13; v++)        //percorre os valores
            baralho[k++] = (Carta){v, naipes[i]};        //cria todas as 13 cartas de um mesmo nipe
}

void embaralhar(Carta b[]) {
    for (int i = 0; i < 52; i++) {        //percorre todas as 52 cartas
        int j = rand() % 52;        //escolhe valores aleatorios de 0 a 52
        Carta t = b[i];
        b[i] = b[j];        //subtitui a carta da possição i pela carta aleatoria j
        b[j] = t;
    }
}

//REGRAS
int podeMoverColuna(Carta a, Carta b) {
    return (cor(a) != cor(b)) && (a.valor == b.valor - 1);        //verifica se a cor é diferente e se o valor é menor em uma vez
}

int podeFundacao(Pilha *f, Carta c) {
    if (vazia(f)) 
        return c.valor == 1;        //verifica se a fundação esta vazia e se a carta é uma As
    Carta t = topo(f);
    return (c.naipe == t.naipe && c.valor == t.valor + 1);        //verifica se a carta é do mesmo nipe e um valor acima
}

//DISPLAY
void mostrar(Pilha col[], Pilha free[], Pilha fund[]) {

    //FREECELLS
    printf("\n========================== FREECELL ===========================\n");
    for (int linha = 0; linha < 5; linha++) {        //cada carta possui 5 linhas
        for (int i = 0; i < FREE; i++)            //percorre as celulas
            printCartaLinha(topo(&free[i]), linha);        //print da carta
        printf("\n");
    }

    //FUNDAÇÕES
    printf("\n========================== FUNDACAO ===========================\n");
    for (int linha = 0; linha < 5; linha++) {        //cada carta possui 5 linhas
        for (int i = 0; i < FUND; i++)            //percorre as fundações
            printCartaLinha(topo(&fund[i]), linha);        //print da carta
        printf("\n");
    }

    //COLUNAS
    printf("\n========================== COLUNAS ============================\n");
    printf("\n|  0  | |  1  | |  2  | |  3  | |  4  | |  5  | |  6  | |  7  | \n");
    printf("\n===============================================================\n"); 

    int maxAltura = 0;        // Descobrir a maior coluna
    for (int i = 0; i < COL; i++) {
        if (col[i].topo > maxAltura)        //compara as alturas
            maxAltura = col[i].topo;        //atualiza maior coluna(necessario para saber quantas cartas sera necessario printar)
    }

    for (int nivel = 0; nivel <= maxAltura; nivel++) {        // Para cada nível de carta (linha vertical das colunas)

        for (int linha = 0; linha < 5; linha++) {        //cada carta tem 5 linhas

            for (int c = 0; c < COL; c++) {        // Percorre todas as colunas

                if (nivel <= col[c].topo)        //verifica se existe uma carta em determido nivel
                    printCartaLinha(col[c].cartas[nivel], linha);        //pinta a carta
                else            //caso não exista
                    printf("        ");        //printa um espaço vazio
            }

            printf("\n");
        }
    }
}
//DISTRIBUIÇÃO
void distribuir(Pilha col[], Carta baralho[]) {
    int k = 0;
    for (int i = 0; i < 52; i++)        //percorre todas as cartas
        push(&col[i % COL], baralho[k++]);        //distribui as cartas nas 8 colunas(i % 8 = resto)
}

//MOVIMENTOS
void moverColuna(Pilha col[], int o, int d) {
    if (vazia(&col[o]))        //verifica se a coluna de origem esta vazia
        return;        //não realiza nenhum movimento

    Carta c = topo(&col[o]);        //carta do topo da pilha

    if (vazia(&col[d]) || podeMoverColuna(c, topo(&col[d])))        //verifica se a coluna de destino esta vazia ou sse pode mover
        push(&col[d], pop(&col[o]));        //realiza o movimento
    else
        printf("Movimento invalido!\n");        //erro
}

void moverFree(Pilha col[], Pilha free[], int o, int f) {

    if (o < 0 || o >= COL || f < 0 || f >= FREE) {        //verifica os parametros de movimento
        printf("Indice invalido!\n");
        return;
    }

    if (vazia(&col[o])) {        //verifica se a coluna de origem esta vazia
        printf("Coluna vazia!\n");
        return;
    }

    if (!vazia(&free[f])) {        //verifica se existe uma carta na free cell
        printf("Freecell ocupada!\n");
        return;
    }

    push(&free[f], pop(&col[o]));        //caso esteja livre = realiza o movimento
}

void freeParaCol(Pilha free[], Pilha col[], int f, int d) {

    if (f < 0 || f >= FREE || d < 0 || d >= COL) {        //verifica os parametros de movimento
        printf("Indice invalido!\n");
        return;
    }

    if (vazia(&free[f])) {            //verifica se a freecell de origem esta vazia
        printf("Freecell vazia!\n");
        return;
    }

    Carta c = topo(&free[f]);

    if (vazia(&col[d]) || podeMoverColuna(c, topo(&col[d]))) {        //caso coluna esteja vazia ou podemover == 0
        push(&col[d], pop(&free[f]));                    //realiza o movimento
    } else {
        printf("Movimento invalido (regra de carta)!\n");        //erro
    }
}

void moverFund(Pilha col[], Pilha fund[], int o, int f) {
    if (vazia(&col[o]))         //verifica se coluna de origem esta vazia
        return;        

    Carta c = topo(&col[o]);

    if (podeFundacao(&fund[f], c))        //verifica os parametros de movimento
        push(&fund[f], pop(&col[o]));        //realiza o movimento
}

//MAIN
int main() {
    srand(time(NULL));        //sistema de aleatoriedade para o embaralhamento

    Carta baralho[52];        //vetor de struct para as cartas
    Pilha col[COL], free[FREE], fund[FUND];        //cria 3 pilhas diferentes

    for (int i = 0; i < COL; i++) 
        init(&col[i]);        //muda o valor da pilha para -1(vazia)
    for (int i = 0; i < FREE; i++) 
        init(&free[i]);        //muda o valor da pilha para -1(vazia)
    for (int i = 0; i < FUND; i++) 
        init(&fund[i]);        //muda o valor da pilha para -1(vazia)

    criarBaralho(baralho);        //cria as 52 cartas
    embaralhar(baralho);        //mistura as cartas
    distribuir(col, baralho);        //distribui nas colunas

    char cmd[20];

   char linha[50];

while (1) {        //loop principal
    mostrar(col, free, fund);        //mostra o estado atual do jogo

    printf("\nComandos:\n");        //mostra os comandos
    printf("move A B   -> coluna A -> B\n");
    printf("free A 0   -> coluna A -> freecell 0 \n");
    printf("back 0 A   -> freecell 0 -> coluna A\n");
    printf("stack A 0  -> coluna A -> fundacao 0 \n");
    printf("sair\n> ");

    fgets(linha, sizeof(linha), stdin);        //le o comando digitado pelo jogador e armazena em "linha"

    char cmd[20];
    int a, b;

    int lidos = sscanf(linha, "%s %d %d", cmd, &a, &b);        //a função sscanf() associa cada codigo digitado a uma variavel diferente

    if (lidos >= 1 && strcmp(cmd, "sair") == 0)        //verifica se o jogador quer encerrar o jogo(sair)
        break;

    if (lidos < 3) {            //verifica se o jogador digitou corretamente
        printf("Entrada invalida!\n");
        continue;
    }

    if (strcmp(cmd, "move") == 0)        //strcmp compara a string com move
        moverColuna(col, a, b);        //move a coluna
    else if (strcmp(cmd, "free") == 0)        //strcmp compara a string com free
        moverFree(col, free, a, b);        //move a coluna
    else if (strcmp(cmd, "back") == 0)        //strcmp compara a string com back
        freeParaCol(free, col, a, b);        //move a coluna
    else if (strcmp(cmd, "stack") == 0)        //strcmp compara a string com stack
        moverFund(col, fund, a, b);        //move a coluna
    else
        printf("Comando desconhecido!\n");        //caso jogador tenha digitado errado = erro
}
    return 0;
}
