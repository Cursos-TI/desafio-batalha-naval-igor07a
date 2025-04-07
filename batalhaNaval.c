#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_HABILIDADE 5

void inicializar_tabuleiro(int tab[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tab[i][j] = 0;
        }
    }
}

// Função para imprimir o tabuleiro com símbolos
void imprimir_tabuleiro(int tab[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("=== Tabuleiro ===\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            if (tab[i][j] == 0) printf("~ ");
            else if (tab[i][j] == 3) printf("N ");
            else if (tab[i][j] == 5) printf("* ");
        }
        printf("\n");
    }
}

// Gera matriz de habilidade cone
void gerar_cone(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            habilidade[i][j] = 0;
            if (j >= (TAM_HABILIDADE / 2 - i) && j <= (TAM_HABILIDADE / 2 + i)) {
                habilidade[i][j] = 1;
            }
        }
    }
}

// Gera matriz de habilidade cruz
void gerar_cruz(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (i == TAM_HABILIDADE / 2 || j == TAM_HABILIDADE / 2) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

// Gera matriz de habilidade octaedro
void gerar_octaedro(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (abs(i - TAM_HABILIDADE / 2) + abs(j - TAM_HABILIDADE / 2) <= TAM_HABILIDADE / 2) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

// Aplica uma habilidade no tabuleiro
void aplicar_habilidade(int tab[TAM_TABULEIRO][TAM_TABULEIRO], int habilidade[TAM_HABILIDADE][TAM_HABILIDADE], int origem_linha, int origem_coluna) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int lin = origem_linha - TAM_HABILIDADE / 2 + i;
            int col = origem_coluna - TAM_HABILIDADE / 2 + j;
            if (lin >= 0 && lin < TAM_TABULEIRO && col >= 0 && col < TAM_TABULEIRO && habilidade[i][j] == 1) {
                if (tab[lin][col] == 0) {
                    tab[lin][col] = 5; // marca área afetada
                }
            }
        }
    }
}

// Posiciona um navio se possível
void posicionar_navio_horizontal(int tab[TAM_TABULEIRO][TAM_TABULEIRO], int lin, int col) {
    if (col + 2 < TAM_TABULEIRO &&
        tab[lin][col] == 0 && tab[lin][col + 1] == 0 && tab[lin][col + 2] == 0) {
        tab[lin][col] = 3;
        tab[lin][col + 1] = 3;
        tab[lin][col + 2] = 3;
    }
}

void posicionar_navio_vertical(int tab[TAM_TABULEIRO][TAM_TABULEIRO], int lin, int col) {
    if (lin + 2 < TAM_TABULEIRO &&
        tab[lin][col] == 0 && tab[lin + 1][col] == 0 && tab[lin + 2][col] == 0) {
        tab[lin][col] = 3;
        tab[lin + 1][col] = 3;
        tab[lin + 2][col] = 3;
    }
}

void posicionar_navio_diagonal_principal(int tab[TAM_TABULEIRO][TAM_TABULEIRO], int lin, int col)_
