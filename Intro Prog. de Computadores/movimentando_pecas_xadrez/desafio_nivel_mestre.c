#include <stdio.h>

// Torre (função recursiva)
// Move a Torre 'n' casas para a direita
void moverTorre(int n) {
    if (n <= 0) return; // Caso base: termina quando não há mais casas
    printf("Direita\n");
    moverTorre(n - 1); // Chamada recursiva reduzindo o contador
}

// Rainha (função recursiva)
// Move a Rainha 'n' casas para a esquerda
void moverRainha(int n) {
    if (n <= 0) return; // Base
    printf("Esquerda\n");
    moverRainha(n - 1); // Recursiva
}

// Bispo (função recursiva com loop aninhado)
// Move o Bispo 'linhas' casas na vertical e 'colunas' casas na horizontal
void moverBispo(int linhas, int colunas) {
    if (linhas <= 0) return; // Caso base para recursão
    // Loop interno para movimento horizontal
    for (int c = 0; c < colunas; c++) {
        printf("Cima, Direita\n");
    }
    // Chamada recursiva para a próxima linha
    moverBispo(linhas - 1, colunas);
}

// Cavalo (loops complexos)
// Cavalo se move em "L": 2 casas para cima e 1 para a direita
void moverCavalo() {
    int casasVerticais = 2; // movimento para cima
    int casasHorizontais = 1; // movimento para a direita

    // Loop externo controla as casas horizontais
    for (int h = 0; h < casasHorizontais; h++) {
        int v = 0; // contador para movimento vertical
        while (v < casasVerticais) {
            printf("Cima\n");
            v++;
            // exemplo de controle de fluxo usando continue
            if (v == 1) continue; // apenas por curiosidade
        }
        printf("Direita\n"); // após subir duas casas, move horizontal
    }
}

// Função principal
int main() {
    int casasTorre = 5;
    int casasBispoLinhas = 5;
    int casasBispoColunas = 1; // diagonal: 1 coluna por linha
    int casasRainha = 8;

    // Movimento da Torre
    printf("Movimento da Torre:\n");
    moverTorre(casasTorre);

    printf("\nMovimento do Bispo:\n");
    moverBispo(casasBispoLinhas, casasBispoColunas);

    printf("\nMovimento da Rainha:\n");
    moverRainha(casasRainha);

    printf("\nMovimento do Cavalo:\n");
    moverCavalo();

    return 0;
}
