#include <stdio.h>

// Estrutura para armazenar os dados de uma carta
typedef struct {
    char estado[3];          // Ex: "SP"
    char codigo[4];          // Ex: "A01"
    char nomeCidade[50];     // Ex: "São Paulo"
    unsigned long int populacao;
    float area;
    float pib;               // em bilhões
    int pontosTuristicos;
    float densidade;
    float pibPerCapita;
} Carta;

// Função para cadastrar os dados de uma carta
void lerCarta(Carta *carta) {
    printf("Estado (ex: SP): ");
    scanf("%s", carta->estado);

    printf("Codigo da carta: ");
    scanf("%s", carta->codigo);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", carta->nomeCidade);

    printf("Populacao: ");
    scanf("%lu", &carta->populacao);

    printf("Area (km²): ");
    scanf("%f", &carta->area);

    printf("PIB (em bilhoes de reais): ");
    scanf("%f", &carta->pib);

    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &carta->pontosTuristicos);

    // Calcula os atributos derivados
    if (carta->area > 0) {
        carta->densidade = carta->populacao / carta->area;
    } else {
        carta->densidade = 0;
    }

    if (carta->populacao > 0) {
        carta->pibPerCapita = (carta->pib * 1000000000.0f) / carta->populacao; 
    } else {
        carta->pibPerCapita = 0;
    }
}

// Função para exibir os dados da carta
void exibirCarta(Carta carta, int numero) {
    printf("\nCarta %d:\n", numero);
    printf("Estado: %s\n", carta.estado);
    printf("Codigo: %s\n", carta.codigo);
    printf("Cidade: %s\n", carta.nomeCidade);
    printf("Populacao: %lu\n", carta.populacao);
    printf("Area: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões de reais\n", carta.pib);
    printf("Pontos Turisticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Demográfica: %.2f hab/km²\n", carta.densidade);
    printf("PIB per Capita: %.2f reais\n", carta.pibPerCapita);
}

// Função para comparar cartas de acordo com a escolha do jogador
void compararCartas(Carta c1, Carta c2, int opcao) {
    printf("\n===== Comparacao de cartas =====\n");
    switch (opcao) {
        case 1: // População
            printf("Atributo: População\n");
            printf("%s: %lu\n", c1.nomeCidade, c1.populacao);
            printf("%s: %lu\n", c2.nomeCidade, c2.populacao);
            if (c1.populacao > c2.populacao)
                printf("Resultado: %s venceu!\n", c1.nomeCidade);
            else if (c2.populacao > c1.populacao)
                printf("Resultado: %s venceu!\n", c2.nomeCidade);
            else
                printf("Resultado: Empate!\n");
            break;

        case 2: // Área
            printf("Atributo: Área\n");
            printf("%s: %.2f km²\n", c1.nomeCidade, c1.area);
            printf("%s: %.2f km²\n", c2.nomeCidade, c2.area);
            if (c1.area > c2.area)
                printf("Resultado: %s venceu!\n", c1.nomeCidade);
            else if (c2.area > c1.area)
                printf("Resultado: %s venceu!\n", c2.nomeCidade);
            else
                printf("Resultado: Empate!\n");
            break;

        case 3: // PIB
            printf("Atributo: PIB\n");
            printf("%s: %.2f bilhões\n", c1.nomeCidade, c1.pib);
            printf("%s: %.2f bilhões\n", c2.nomeCidade, c2.pib);
            if (c1.pib > c2.pib)
                printf("Resultado: %s venceu!\n", c1.nomeCidade);
            else if (c2.pib > c1.pib)
                printf("Resultado: %s venceu!\n", c2.nomeCidade);
            else
                printf("Resultado: Empate!\n");
            break;

        case 4: // Pontos turísticos
            printf("Atributo: Pontos Turísticos\n");
            printf("%s: %d\n", c1.nomeCidade, c1.pontosTuristicos);
            printf("%s: %d\n", c2.nomeCidade, c2.pontosTuristicos);
            if (c1.pontosTuristicos > c2.pontosTuristicos)
                printf("Resultado: %s venceu!\n", c1.nomeCidade);
            else if (c2.pontosTuristicos > c1.pontosTuristicos)
                printf("Resultado: %s venceu!\n", c2.nomeCidade);
            else
                printf("Resultado: Empate!\n");
            break;

        case 5: // Densidade demográfica (menor vence)
            printf("Atributo: Densidade Demográfica\n");
            printf("%s: %.2f hab/km²\n", c1.nomeCidade, c1.densidade);
            printf("%s: %.2f hab/km²\n", c2.nomeCidade, c2.densidade);
            if (c1.densidade < c2.densidade)
                printf("Resultado: %s venceu!\n", c1.nomeCidade);
            else if (c2.densidade < c1.densidade)
                printf("Resultado: %s venceu!\n", c2.nomeCidade);
            else
                printf("Resultado: Empate!\n");
            break;

        default: // Opção inválida
            printf("Opcao invalida! Tente novamente.\n");
            break;
    }
}

int main() {
    Carta carta1, carta2;
    int opcao;

    printf("Digite os dados da Carta 1:\n");
    lerCarta(&carta1);

    printf("\nDigite os dados da Carta 2:\n");
    lerCarta(&carta2);

    exibirCarta(carta1, 1);
    exibirCarta(carta2, 2);

    // Menu interativo
    printf("\n===== MENU DE COMPARACAO =====\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Escolha o atributo para comparação: ");
    scanf("%d", &opcao);

    // Faz a comparação conforme a opção escolhida
    compararCartas(carta1, carta2, opcao);

    return 0;
}