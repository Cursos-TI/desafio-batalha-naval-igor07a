#include <stdio.h>

int main() {
    int tabuleiro[10][10];
    int i, j;

    // Inicializa o tabuleiro com 0 (água)
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // ===== NAVIO 1: HORIZONTAL =====
    int linhaH = 2;
    int colunaH = 4;
    if (colunaH + 2 < 10 &&
        tabuleiro[linhaH][colunaH] == 0 &&
        tabuleiro[linhaH][colunaH + 1] == 0 &&
        tabuleiro[linhaH][colunaH + 2] == 0) {

        tabuleiro[linhaH][colunaH] = 3;
        tabuleiro[linhaH][colunaH + 1] = 3;
        tabuleiro[linhaH][colunaH + 2] = 3;
    }

    // ===== NAVIO 2: VERTICAL =====
    int linhaV = 5;
    int colunaV = 1;
    if (linhaV + 2 < 10 &&
        tabuleiro[linhaV][colunaV] == 0 &&
        tabuleiro[linhaV + 1][colunaV] == 0 &&
        tabuleiro[linhaV + 2][colunaV] == 0) {

        tabuleiro[linhaV][colunaV] = 3;
        tabuleiro[linhaV + 1][colunaV] = 3;
        tabuleiro[linhaV + 2][colunaV] = 3;
    }

    // ===== NAVIO 3: DIAGONAL PRINCIPAL =====
    int linhaD1 = 0;
    int colunaD1 = 0;
    if (linhaD1 + 2 < 10 && colunaD1 + 2 < 10 &&
        tabuleiro[linhaD1][colunaD1] == 0 &&
        tabuleiro[linhaD1 + 1][colunaD1 + 1] == 0 &&
        tabuleiro[linhaD1 + 2][colunaD1 + 2] == 0) {

        tabuleiro[linhaD1][colunaD1] = 3;
        tabuleiro[linhaD1 + 1][colunaD1 + 1] = 3;
        tabuleiro[linhaD1 + 2][colunaD1 + 2] = 3;
    }

    // ===== NAVIO 4: DIAGONAL SECUNDÁRIA =====
    int linhaD2 = 0;
    int colunaD2 = 9;
    if (linhaD2 + 2 < 10 && colunaD2 - 2 >= 0 &&
        tabuleiro[linhaD2][colunaD2] == 0 &&
        tabuleiro[linhaD2 + 1][colunaD2 - 1] == 0 &&
        tabuleiro[linhaD2 + 2][colunaD2 - 2] == 0) {

        tabuleiro[linhaD2][colunaD2] = 3;
        tabuleiro[linhaD2 + 1][colunaD2 - 1] = 3;
        tabuleiro[linhaD2 + 2][colunaD2 - 2] = 3;
    }

    // ===== IMPRIME O TABULEIRO =====
    printf("=== Tabuleiro ===\n");
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
