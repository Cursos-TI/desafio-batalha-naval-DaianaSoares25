#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define NAVIO 3
#define AGUA 0

// Função para exibir o tabuleiro com espaçamento organizado
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\n=== TABULEIRO ===\n\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para verificar se uma posição já está ocupada por outro navio
int estaOcupado(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    return tabuleiro[linha][coluna] == NAVIO;
}

// Função principal
int main() {
    // Inicializa o tabuleiro com 0 (água)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // --- POSICIONAMENTO DOS NAVIOS ---

    // Navio 1 - Horizontal (linha 2, coluna 1 a 3)
    int linhaH1 = 2, colunaH1 = 1;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (!estaOcupado(tabuleiro, linhaH1, colunaH1 + i)) {
            tabuleiro[linhaH1][colunaH1 + i] = NAVIO;
        }
    }

    // Navio 2 - Vertical (linha 5 a 7, coluna 6)
    int linhaV1 = 5, colunaV1 = 6;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (!estaOcupado(tabuleiro, linhaV1 + i, colunaV1)) {
            tabuleiro[linhaV1 + i][colunaV1] = NAVIO;
        }
    }

    // Navio 3 - Diagonal principal (começando em 0,0 até 2,2)
    int linhaD1 = 0, colunaD1 = 0;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (!estaOcupado(tabuleiro, linhaD1 + i, colunaD1 + i)) {
            tabuleiro[linhaD1 + i][colunaD1 + i] = NAVIO;
        }
    }

    // Navio 4 - Diagonal secundária (começando em 0,9 até 2,7)
    int linhaD2 = 0, colunaD2 = 9;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (!estaOcupado(tabuleiro, linhaD2 + i, colunaD2 - i)) {
            tabuleiro[linhaD2 + i][colunaD2 - i] = NAVIO;
        }
    }

    // --- EXIBIR O TABULEIRO FINAL ---
    exibirTabuleiro(tabuleiro);

    return 0;
}
