#include <stdio.h>
#include <stdlib.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define TAM_HABILIDADE 5  // Matrizes de habilidade
#define VALOR_NAVIO 3
#define VALOR_HABILIDADE 5

// Exibir tabuleiro
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("Tabuleiro com Habilidades (0=água, 3=navio, 5=habilidade):\n\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {0};

    // Posicionando navios
    int navios[4][2] = {{1, 1}, {4, 5}, {0, 7}, {7, 2}}; // coordenadas iniciais
    // Horizontal e vertical
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[1][1+i] = VALOR_NAVIO; // horizontal
        tabuleiro[4+i][5] = VALOR_NAVIO; // vertical
        tabuleiro[0+i][7+i] = VALOR_NAVIO; // diagonal 
        tabuleiro[7+i][2-i] = VALOR_NAVIO; // diagonal 
    }

    // Criando matrizes de habilidade
    int cone[TAM_HABILIDADE][TAM_HABILIDADE] = {0};
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE] = {0};
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE] = {0};

    // Matriz Cone (forma de triângulo apontando para baixo)
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = TAM_HABILIDADE/2 - i; j <= TAM_HABILIDADE/2 + i; j++) {
            if (j >= 0 && j < TAM_HABILIDADE) {
                cone[i][j] = 1;
            }
        }
    }

    // Matriz Cruz
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (i == TAM_HABILIDADE/2 || j == TAM_HABILIDADE/2) {
                cruz[i][j] = 1;
            }
        }
    }

    // Matriz Octaedro
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (abs(TAM_HABILIDADE/2 - i) + abs(TAM_HABILIDADE/2 - j) <= TAM_HABILIDADE/2) {
                octaedro[i][j] = 1;
            }
        }
    }

    // Pontos de origem das habilidades no tabuleiro
    int origemConeLinha = 2, origemConeColuna = 2;
    int origemCruzLinha = 5, origemCruzColuna = 5;
    int origemOctaedroLinha = 7, origemOctaedroColuna = 7;

    // Aplicando habilidades no tabuleiro
    // Cone
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int linha = origemConeLinha + i - TAM_HABILIDADE/2;
            int coluna = origemConeColuna + j - TAM_HABILIDADE/2;
            if (linha >=0 && linha < TAM_TABULEIRO && coluna >=0 && coluna < TAM_TABULEIRO && cone[i][j] == 1) {
                if (tabuleiro[linha][coluna] == 0) tabuleiro[linha][coluna] = VALOR_HABILIDADE;
            }
        }
    }

    // Cruz
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int linha = origemCruzLinha + i - TAM_HABILIDADE/2;
            int coluna = origemCruzColuna + j - TAM_HABILIDADE/2;
            if (linha >=0 && linha < TAM_TABULEIRO && coluna >=0 && coluna < TAM_TABULEIRO && cruz[i][j] == 1) {
                if (tabuleiro[linha][coluna] == 0) tabuleiro[linha][coluna] = VALOR_HABILIDADE;
            }
        }
    }

    // Octaedro
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int linha = origemOctaedroLinha + i - TAM_HABILIDADE/2;
            int coluna = origemOctaedroColuna + j - TAM_HABILIDADE/2;
            if (linha >=0 && linha < TAM_TABULEIRO && coluna >=0 && coluna < TAM_TABULEIRO && octaedro[i][j] == 1) {
                if (tabuleiro[linha][coluna] == 0) tabuleiro[linha][coluna] = VALOR_HABILIDADE;
            }
        }
    }

    // 5. Exibir o tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}
