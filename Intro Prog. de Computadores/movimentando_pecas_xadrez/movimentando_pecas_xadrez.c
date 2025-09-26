#include <stdio.h>

int main() {
    // Torre (for)
    int casasTorre = 5; // número de casas que a Torre deve se mover
    printf("Movimento da Torre:\n");
    for (int i = 1; i <= casasTorre; i++) {
        printf("Direita\n");
    }

    // Bispo (while)
    int casasBispo = 5; // número de casas que o Bispo deve se mover
    int i = 1;
    printf("\nMovimento do Bispo:\n");
    while (i <= casasBispo) {
        printf("Cima, Direita\n");
        i++;
    }

    // Rainha (do-while)
    int casasRainha = 8; // número de casas que a Rainha deve se mover
    int j = 1;
    printf("\nMovimento da Rainha:\n");
    do {
        printf("Esquerda\n");
        j++;
    } while (j <= casasRainha);

    // Cavalo (loops aninhados)
    // O Cavalo se move em "L": 2 casas para baixo e 1 para a esquerda
    int movimentosVerticais = 2; // casas verticais (para baixo)
    int movimentosHorizontais = 1; // casas horizontais (para esquerda)
    
    printf("\nMovimento do Cavalo:\n");
    
    // Loop externo (movimento horizontal)
    for (int h = 0; h < movimentosHorizontais; h++) {
        int v = 0; // contador do loop interno (vertical)
        // Loop interno (movimento vertical com while)
        while (v < movimentosVerticais) {
            printf("Baixo\n");
            v++;
        }
        // Após descer duas casas, move uma casa para a esquerda
        printf("Esquerda\n");
    }

    return 0;
}
