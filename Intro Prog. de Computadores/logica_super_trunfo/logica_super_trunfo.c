#include <stdio.h>

// Armazena os dados da carta (aprendido na aula anterior)
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

// Cadastrar os dados de uma carta
void lerCarta(Carta *carta) {
    printf("Estado (ex: SP): ");
    scanf("%s", carta->estado);

    printf("Codigo da carta (ex: A02): ");
    scanf("%s", carta->codigo);

    printf("Nome da Cidade (ex: Santos): ");
    scanf(" %[^\n]", carta->nomeCidade);

    printf("Populacao: ");
    scanf("%lu", &carta->populacao);

    printf("Area (km²): ");
    scanf("%f", &carta->area);

    printf("PIB (em bilhoes de reais): ");
    scanf("%f", &carta->pib);

    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &carta->pontosTuristicos);

    // Cálculo dos atributos derivados
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

// Exibição dos dados da carta
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

// Comparar valores de acordo com a regra (lembrar que a densidade é invertida)
int compararAtributo(float v1, float v2, int atributo) {
    if (atributo == 5) { // Densidade demográfica: menor ganha
        if (v1 < v2) return 1;
        else if (v2 < v1) return 2;
        else return 0;
    } else { // Outros atributos: maior ganha
        if (v1 > v2) return 1;
        else if (v2 > v1) return 2;
        else return 0;
    }
}

// Obter o valor de um atributo específico
float getValorAtributo(Carta c, int atributo) {
    switch (atributo) {
        case 1: return (float)c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return (float)c.pontosTuristicos;
        case 5: return c.densidade;
        default: return 0;
    }
}

// Obter o nome do atributo
const char* nomeAtributo(int atributo) {
    switch (atributo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Demográfica";
        default: return "Inválido";
    }
}

int main() {
    Carta carta1, carta2;
    int opcao1, opcao2;

    printf("Digite os dados da Carta 1:\n");
    lerCarta(&carta1);

    printf("\nDigite os dados da Carta 2:\n");
    lerCarta(&carta2);

    exibirCarta(carta1, 1);
    exibirCarta(carta2, 2);

    // Menu - primeira escolha
    printf("\n====== MENU DE COMPARACAO ======\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Escolha o primeiro atributo: ");
    scanf("%d", &opcao1);

    // Menu - segunda escolha (sem repetir)
    printf("\n====== SEGUNDA ESCOLHA ======\n");
    for (int i = 1; i <= 5; i++) {
        if (i != opcao1) {
            printf("%d - %s\n", i, nomeAtributo(i));
        }
    }
    printf("Escolha o segundo atributo (diferente do primeiro): ");
    scanf("%d", &opcao2);

    if (opcao1 == opcao2) {
        printf("Erro: não é permitido escolher o mesmo atributo duas vezes!\n");
        return 1;
    }

    // Obter valores dos atributos
    float v1_attr1 = getValorAtributo(carta1, opcao1);
    float v2_attr1 = getValorAtributo(carta2, opcao1);
    float v1_attr2 = getValorAtributo(carta1, opcao2);
    float v2_attr2 = getValorAtributo(carta2, opcao2);

    // Mostrar os resultados individuais
    printf("\n====== RESULTADOS INDIVIDUAIS ======\n");
    printf("%s: %s = %.2f | %s = %.2f\n",
           nomeAtributo(opcao1), carta1.nomeCidade, v1_attr1, carta2.nomeCidade, v2_attr1);
    printf("%s: %s = %.2f | %s = %.2f\n",
           nomeAtributo(opcao2), carta1.nomeCidade, v1_attr2, carta2.nomeCidade, v2_attr2);

    // Comparações individuais
    int res1 = compararAtributo(v1_attr1, v2_attr1, opcao1);
    int res2 = compararAtributo(v1_attr2, v2_attr2, opcao2);

    if (res1 == 1) printf("No atributo %s, %s venceu!\n", nomeAtributo(opcao1), carta1.nomeCidade);
    else if (res1 == 2) printf("No atributo %s, %s venceu!\n", nomeAtributo(opcao1), carta2.nomeCidade);
    else printf("No atributo %s, houve empate!\n", nomeAtributo(opcao1));

    if (res2 == 1) printf("No atributo %s, %s venceu!\n", nomeAtributo(opcao2), carta1.nomeCidade);
    else if (res2 == 2) printf("No atributo %s, %s venceu!\n", nomeAtributo(opcao2), carta2.nomeCidade);
    else printf("No atributo %s, houve empate!\n", nomeAtributo(opcao2));

    // Somar atributos
    float soma1 = v1_attr1 + v1_attr2;
    float soma2 = v2_attr1 + v2_attr2;

    printf("\n====== SOMA DOS ATRIBUTOS ======\n");
    printf("%s: %.2f\n", carta1.nomeCidade, soma1);
    printf("%s: %.2f\n", carta2.nomeCidade, soma2);

    if (soma1 > soma2)
        printf("\nResultado Final: %s venceu a rodada!\n", carta1.nomeCidade);
    else if (soma2 > soma1)
        printf("\nResultado Final: %s venceu a rodada!\n", carta2.nomeCidade);
    else
        printf("\nResultado Final: Empate!\n");

    return 0;
}
