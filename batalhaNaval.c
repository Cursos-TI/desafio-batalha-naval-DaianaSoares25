#include <stdio.h>

#define TAM 10        
#define TAM_HAB 5     
#define NAVIO 3       
#define AGUA 0        
#define HABILIDADE 5  

// Exibe o tabuleiro no console com representação visual
void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("\n=== TABULEIRO ===\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] == AGUA) printf("~ ");        
            else if (tabuleiro[i][j] == NAVIO) printf("N ");  
            else if (tabuleiro[i][j] == HABILIDADE) printf("* ");
        }
        printf("\n");
    }
}

// Constrói uma matriz em forma de cone
void construirCone(int matriz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            int meio = TAM_HAB / 2;
            if (j >= meio - i && j <= meio + i)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Constrói uma matriz em forma de cruz
void construirCruz(int matriz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i == TAM_HAB / 2 || j == TAM_HAB / 2)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Constrói uma matriz com forma de octaedro (losango)
void construirOctaedro(int matriz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            int meio = TAM_HAB / 2;
            if (abs(meio - i) + abs(meio - j) <= meio)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Sobrepõe a matriz de habilidade ao tabuleiro em uma posição central (linha, coluna)
void aplicarHabilidade(int tabuleiro[TAM][TAM], int matriz[TAM_HAB][TAM_HAB], int linhaCentro, int colCentro) {
    int offset = TAM_HAB / 2;
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            int linha = linhaCentro - offset + i;
            int coluna = colCentro - offset + j;

            // Verifica se a posição está dentro dos limites
            if (linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM) {
                if (matriz[i][j] == 1 && tabuleiro[linha][coluna] == AGUA) {
                    tabuleiro[linha][coluna] = HABILIDADE;
                }
            }
        }
    }
}

// Função principal
int main() {
    int tabuleiro[TAM][TAM] = {0};

    // --- POSICIONAR ALGUNS NAVIOS COMO EXEMPLO ---
    for (int i = 2; i < 5; i++) tabuleiro[1][i] = NAVIO;         // horizontal
    for (int i = 6; i < 9; i++) tabuleiro[i][4] = NAVIO;         // vertical
    for (int i = 0; i < 3; i++) tabuleiro[i][i] = NAVIO;         // diagonal principal
    for (int i = 0; i < 3; i++) tabuleiro[i][9 - i] = NAVIO;     // diagonal secundária

    // --- MATRIZES DAS HABILIDADES ---
    int cone[TAM_HAB][TAM_HAB];
    int cruz[TAM_HAB][TAM_HAB];
    int octaedro[TAM_HAB][TAM_HAB];

    construirCone(cone);
    construirCruz(cruz);
    construirOctaedro(octaedro);

    // --- APLICAR HABILIDADES EM PONTOS ESPECÍFICOS ---
    aplicarHabilidade(tabuleiro, cone, 2, 5);      
    aplicarHabilidade(tabuleiro, cruz, 6, 6);    
    aplicarHabilidade(tabuleiro, octaedro, 5, 2);  

    // --- EXIBIR O TABULEIRO FINAL ---
    exibirTabuleiro(tabuleiro);

    return 0;
}
