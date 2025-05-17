#include <stdio.h>

#define NUM_CARTAS 2

// Definição da estrutura da carta da cidade
struct CartaCidade {
    char estado;
    char codigo[4]; // Exemplo: A01
    char nomeCidade[100];
    int populacao;
    float area;
    float pib; // Em bilhões de reais
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
};

// Função para registrar os dados da carta
void registrarCarta(struct CartaCidade *carta) {
    printf("\n--- Registro da Carta ---\n");

    printf("Estado (A-H): ");
    scanf(" %c", &carta->estado);

    printf("Código da Carta (ex: A01): ");
    scanf(" %3s", carta->codigo);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", carta->nomeCidade);

    printf("População: ");
    scanf("%d", &carta->populacao);

    printf("Área (em km2): ");
    scanf("%f", &carta->area);

    printf("PIB (em bilhões de reais): ");
    scanf("%f", &carta->pib);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta->pontosTuristicos);

    // Cálculos
    carta->densidadePopulacional = carta->populacao / carta->area;
    float pibTotalReais = carta->pib * 1000000000; // converter para reais
    carta->pibPerCapita = pibTotalReais / carta->populacao;
}

// Função para exibir os dados da carta
void exibirCarta(struct CartaCidade carta, int indice) {
    printf("\nCarta %d:\n", indice + 1);
    printf("Estado: %c\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("Nome da Cidade: %s\n", carta.nomeCidade);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km2\n", carta.area);
    printf("PIB: %.2f bilhões de reais\n", carta.pib);
    printf("Número de Pontos Turísticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km2\n", carta.densidadePopulacional);
    printf("PIB per Capita: %.2f reais\n", carta.pibPerCapita);
}

int main() {
    struct CartaCidade cartas[NUM_CARTAS];

    // Registro das cartas
    for (int i = 0; i < NUM_CARTAS; i++) {
        printf("\nCadastro da carta %d:\n", i + 1);
        registrarCarta(&cartas[i]);
    }

    // Exibição das cartas
    for (int i = 0; i < NUM_CARTAS; i++) {
        exibirCarta(cartas[i], i);
    }

    return 0;
}
