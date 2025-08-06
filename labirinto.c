
#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define LINHAS 5
#define COLUNAS 5

// Estrutura para coordenadas
typedef struct {
    int linha;
    int coluna;
} Posicao;

// Estrutura de Pilha
typedef struct {
    Posicao itens[MAX];
    int topo;
} Pilha;

// Inicializar a pilha
void inicializarPilha(Pilha* p) {
    p->topo = -1;
}

// Verificar se a pilha está vazia
int pilhaVazia(Pilha* p) {
    return p->topo == -1;
}

// Inserir na pilha
void empilhar(Pilha* p, Posicao pos) {
    if (p->topo < MAX - 1) {
        p->itens[++p->topo] = pos;
    }
}

// Retirar da pilha
Posicao desempilhar(Pilha* p) {
    return p->itens[p->topo--];
}

// Labirinto de exemplo
char labirinto[LINHAS][COLUNAS] = {
    {'#', '#', '#', '#', '#'},
    {'#', ' ', ' ', ' ', '#'},
    {'#', ' ', '#', ' ', '#'},
    {'#', '*', '#', '$', '#'},
    {'#', '#', '#', '#', '#'}
};

// Verifica se a posição pode ser visitada
int posicaoValida(int linha, int coluna) {
    return linha >= 0 && linha < LINHAS &&
           coluna >= 0 && coluna < COLUNAS &&
           labirinto[linha][coluna] != '#' &&
           labirinto[linha][coluna] != '.';
}

// Algoritmo de resolução do labirinto
int resolverLabirinto() {
    Pilha p;
    inicializarPilha(&p);

    // Encontrar posição inicial (*)
    Posicao inicio;
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            if (labirinto[i][j] == '*') {
                inicio.linha = i;
                inicio.coluna = j;
            }
        }
    }

    empilhar(&p, inicio);

    while (!pilhaVazia(&p)) {
        Posicao atual = desempilhar(&p);
        int i = atual.linha;
        int j = atual.coluna;

        if (labirinto[i][j] == '$') {
            printf("Tesouro encontrado na posição (%d, %d)!\n", i, j);
            return 1;
        }

        // Marcar como visitado
        if (labirinto[i][j] != '*')
            labirinto[i][j] = '.';

        // Verificar posições vizinhas
        Posicao vizinhos[4] = {
            {i-1, j}, {i+1, j}, {i, j-1}, {i, j+1}
        };

        for (int k = 0; k < 4; k++) {
            int ni = vizinhos[k].linha;
            int nj = vizinhos[k].coluna;
            if (posicaoValida(ni, nj)) {
                empilhar(&p, vizinhos[k]);
            }
        }
    }

    printf("Não foi possível encontrar o tesouro.\n");
    return 0;
}

int main() {
    resolverLabirinto();
    return 0;
}
