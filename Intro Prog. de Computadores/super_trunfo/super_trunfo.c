#include <stdio.h>

// Armazenar os dados de uma carta
typedef struct {
    char estado;
    char codigo[4];
    char nomeCidade[50];
    unsigned long int populacao;
    float area;
    float pib; // em bilhões
    int pontosTuristicos;
    float densidade;
    float pibPerCapita;
    float superPoder;
} Carta;

// Ler os dados de uma carta
void lerCarta(Carta *carta) {
    printf("Estado: ");
    scanf(" %c", &carta->estado);
    printf("Codigo: ");
    scanf("%s", carta->codigo);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", carta->nomeCidade);
    printf("Populacao: ");
    scanf("%lu", &carta->populacao);
    printf("Area (km²): ");
    scanf("%f", &carta->area);
    printf("PIB (bilhoes): ");
    scanf("%f", &carta->pib);
    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &carta->pontosTuristicos);
}
// Calcular densidade, PIB per capita e Super Poder
void calcularAtributos(Carta *carta) {
    carta->densidade = carta->populacao / carta->area;
    carta->pibPerCapita = (carta->pib * 1000000000) / carta->populacao; // PIB em reais
    carta->superPoder = (float)carta->populacao + carta->area + (carta->pib * 1000000000)
                        + carta->pontosTuristicos + carta->pibPerCapita + (1.0 / carta->densidade);
}

// Função para exibir os dados de uma carta
void exibirCarta(Carta carta, int numero) {
    printf("\nCarta %d:\n", numero);
    printf("Estado: %c\n", carta.estado);
    printf("Codigo: %s\n", carta.codigo);
    printf("Nome da Cidade: %s\n", carta.nomeCidade);
    printf("Populacao: %lu\n", carta.populacao);
    printf("Area: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhoes de reais\n", carta.pib);
    printf("Numero de Pontos Turisticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidade);
    printf("PIB per Capita: %.2f reais\n", carta.pibPerCapita);
    printf("Super Poder: %.2f\n", carta.superPoder);
}

// Função para comparar duas cartas e exibir o vencedor de cada atributo
void compararCartas(Carta c1, Carta c2) {
    printf("\nComparacao de Cartas:\n");
    printf("Populacao: Carta 1 venceu (%d)\n", c1.populacao > c2.populacao ? 1 : 0);
    printf("Area: Carta 1 venceu (%d)\n", c1.area > c2.area ? 1 : 0);
    printf("PIB: Carta 1 venceu (%d)\n", c1.pib > c2.pib ? 1 : 0);
    printf("Pontos Turisticos: Carta 1 venceu (%d)\n", c1.pontosTuristicos > c2.pontosTuristicos ? 1 : 0);
    printf("Densidade Populacional: Carta 1 venceu (%d)\n", c1.densidade < c2.densidade ? 1 : 0); // menor vence
    printf("PIB per Capita: Carta 1 venceu (%d)\n", c1.pibPerCapita > c2.pibPerCapita ? 1 : 0);
    printf("Super Poder: Carta 1 venceu (%d)\n", c1.superPoder > c2.superPoder ? 1 : 0);
}

int main() {
    Carta carta1, carta2;

    printf("Digite os dados da Carta 1:\n");
    lerCarta(&carta1);
    calcularAtributos(&carta1);

    printf("\nDigite os dados da Carta 2:\n");
    lerCarta(&carta2);
    calcularAtributos(&carta2);

    exibirCarta(carta1, 1);
    exibirCarta(carta2, 2);

    compararCartas(carta1, carta2);

    return 0;
}
