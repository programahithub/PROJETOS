#include <stdio.h>

#define NUM_CARTAS 2

// Definindo a estrutura da carta
struct CartaCidade {
    char estado;
    char codigo[4]; // Exemplo: A01, B03 (3 caracteres + 1 '\0')
    char nomeCidade[100];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
};

// Função para registrar uma carta
void registrarCarta(struct CartaCidade *carta) {
    printf("\n--- Registro de Carta ---\n");

    printf("Digite o estado (A-H): ");
    scanf(" %c", &carta->estado);

    printf("Digite o código da carta (ex: A01): ");
    scanf(" %3s", carta->codigo);

    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", carta->nomeCidade);

    printf("Digite a população da cidade: ");
    scanf("%d", &carta->populacao);

    printf("Digite a área da cidade (em km²): ");
    scanf("%f", &carta->area);

    printf("Digite o PIB da cidade: ");
    scanf("%f", &carta->pib);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta->pontosTuristicos);
}

// Função para exibir uma carta
void exibirCarta(struct CartaCidade carta) {
    printf("\n--- Carta da Cidade ---\n");
    printf("Estado: %c\n", carta.estado);
    printf("Código da Carta: %s\n", carta.codigo);
    printf("Nome da Cidade: %s\n", carta.nomeCidade);
    printf("População: %d habitantes\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: R$ %.2f\n", carta.pib);
    printf("Número de Pontos Turísticos: %d\n", carta.pontosTuristicos);
}

int main() {
    struct CartaCidade cartas[NUM_CARTAS];

    // Cadastro das cartas
    for (int i = 0; i < NUM_CARTAS; i++) {
        printf("\nCadastro da carta %d:\n", i + 1);
        registrarCarta(&cartas[i]);
    }

    // Exibição das cartas
    for (int i = 0; i < NUM_CARTAS; i++) {
        printf("\nExibindo a carta %d:\n", i + 1);
        exibirCarta(cartas[i]);
    }

    return 0;
}
