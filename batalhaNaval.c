#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

// Função para imprimir o tabuleiro de forma organizada
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\n=== TABULEIRO ===\n\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Inicializa o tabuleiro com 0 (água)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Definimos os dois navios com tamanho 3
    int navioHorizontal[TAMANHO_NAVIO] = {3, 3, 3};
    int navioVertical[TAMANHO_NAVIO] = {3, 3, 3};

    // Coordenadas iniciais escolhidas diretamente no código
    int linhaH = 2; 
    int colunaH = 4;

    int linhaV = 5; 
    int colunaV = 7; 

    // Garantir que os navios estão dentro dos limites e não se sobrepõem
    if (colunaH + TAMANHO_NAVIO <= TAMANHO_TABULEIRO && linhaV + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        int sobreposicao = 0;

        // Verifica sobreposição nas posições do navio vertical e horizontal
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (linhaH == linhaV + i && (colunaH <= colunaV && colunaH + 2 >= colunaV)) {
                sobreposicao = 1;
                break;
            }
        }

        if (!sobreposicao) {
            // Posiciona o navio horizontal
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
            }

            // Posiciona o navio vertical
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linhaV + i][colunaV] = navioVertical[i];
            }

            // Exibe o tabuleiro final com os navios posicionados
            exibirTabuleiro(tabuleiro);

        } else {
            printf("Erro: Os navios se sobrepõem. Tente outras coordenadas.\n");
        }
    } else {
        printf("Erro: As coordenadas dos navios ultrapassam os limites do tabuleiro.\n");
    }

    return 0;
}
