#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_CARTAS 2

struct CartaCidade {
    char estado;
    char codigo[4];
    char nomeCidade[100];
    unsigned long int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
    float superPoder;
};

void registrarCarta(struct CartaCidade *carta) {
    printf("\n--- Registro da Carta ---\n");

    printf("Estado (A-H): ");
    scanf(" %c", &carta->estado);

    printf("Código da Carta (ex: A01): ");
    scanf(" %3s", carta->codigo);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", carta->nomeCidade);

    printf("População: ");
    scanf("%lu", &carta->populacao);

    printf("Área (em km2): ");
    scanf("%f", &carta->area);

    printf("PIB (em bilhões de reais): ");
    scanf("%f", &carta->pib);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta->pontosTuristicos);

    // Cálculos
    carta->densidadePopulacional = carta->populacao / carta->area;
    float pibReais = carta->pib * 1000000000.0;
    carta->pibPerCapita = pibReais / carta->populacao;
    carta->superPoder = (float)carta->populacao + carta->area + carta->pib +
                        carta->pontosTuristicos + carta->pibPerCapita +
                        (1.0 / carta->densidadePopulacional);
}

void exibirCarta(struct CartaCidade carta, int indice) {
    printf("\nCarta %d:\n", indice + 1);
    printf("Estado: %c\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("Nome da Cidade: %s\n", carta.nomeCidade);
    printf("População: %lu\n", carta.populacao);
    printf("Área: %.2f km2\n", carta.area);
    printf("PIB: %.2f bilhões de reais\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km2\n", carta.densidadePopulacional);
    printf("PIB per Capita: %.2f reais\n", carta.pibPerCapita);
    printf("Super Poder: %.2f\n", carta.superPoder);
}

void salvarEmArquivo(struct CartaCidade c1, struct CartaCidade c2) {
    FILE *arquivo = fopen("resultado_cartas.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao criar arquivo!\n");
        return;
    }

    fprintf(arquivo, "=== CARTA 1 ===\n");
    fprintf(arquivo, "Estado: %c\nCódigo: %s\nNome: %s\nPopulação: %lu\nÁrea: %.2f km2\nPIB: %.2f bilhões\nPontos Turísticos: %d\nDensidade: %.2f\nPIB per Capita: %.2f\nSuper Poder: %.2f\n\n",
            c1.estado, c1.codigo, c1.nomeCidade, c1.populacao, c1.area, c1.pib, c1.pontosTuristicos,
            c1.densidadePopulacional, c1.pibPerCapita, c1.superPoder);

    fprintf(arquivo, "=== CARTA 2 ===\n");
    fprintf(arquivo, "Estado: %c\nCódigo: %s\nNome: %s\nPopulação: %lu\nÁrea: %.2f km2\nPIB: %.2f bilhões\nPontos Turísticos: %d\nDensidade: %.2f\nPIB per Capita: %.2f\nSuper Poder: %.2f\n\n",
            c2.estado, c2.codigo, c2.nomeCidade, c2.populacao, c2.area, c2.pib, c2.pontosTuristicos,
            c2.densidadePopulacional, c2.pibPerCapita, c2.superPoder);

    fprintf(arquivo, "=== COMPARAÇÃO ===\n");
    fprintf(arquivo, "População: Carta 1 venceu (%d)\n", c1.populacao > c2.populacao);
    fprintf(arquivo, "Área: Carta 1 venceu (%d)\n", c1.area > c2.area);
    fprintf(arquivo, "PIB: Carta 1 venceu (%d)\n", c1.pib > c2.pib);
    fprintf(arquivo, "Pontos Turísticos: Carta 1 venceu (%d)\n", c1.pontosTuristicos > c2.pontosTuristicos);
    fprintf(arquivo, "Densidade Populacional: Carta 1 venceu (%d)\n", c1.densidadePopulacional < c2.densidadePopulacional);
    fprintf(arquivo, "PIB per Capita: Carta 1 venceu (%d)\n", c1.pibPerCapita > c2.pibPerCapita);
    fprintf(arquivo, "Super Poder: Carta 1 venceu (%d)\n", c1.superPoder > c2.superPoder);

    fclose(arquivo);
    printf("\nResultados salvos em 'resultado_cartas.txt'\n");
}

void compararCartas(struct CartaCidade c1, struct CartaCidade c2) {
    printf("\n--- Comparação de Cartas ---\n");
    printf("População: Carta 1 venceu (%d)\n", c1.populacao > c2.populacao);
    printf("Área: Carta 1 venceu (%d)\n", c1.area > c2.area);
    printf("PIB: Carta 1 venceu (%d)\n", c1.pib > c2.pib);
    printf("Pontos Turísticos: Carta 1 venceu (%d)\n", c1.pontosTuristicos > c2.pontosTuristicos);
    printf("Densidade Populacional: Carta 1 venceu (%d)\n", c1.densidadePopulacional < c2.densidadePopulacional);
    printf("PIB per Capita: Carta 1 venceu (%d)\n", c1.pibPerCapita > c2.pibPerCapita);
    printf("Super Poder: Carta 1 venceu (%d)\n", c1.superPoder > c2.superPoder);
}

int main() {
    struct CartaCidade cartas[NUM_CARTAS];
    int cadastradas = 0;
    int opcao;

    do {
        printf("\n==== MENU ====\n");
        printf("1. Cadastrar Cartas\n");
        printf("2. Exibir Cartas\n");
        printf("3. Comparar Cartas\n");
        printf("4. Salvar Resultados em Arquivo\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                for (int i = 0; i < NUM_CARTAS; i++) {
                    printf("\nCadastro da Carta %d:\n", i + 1);
                    registrarCarta(&cartas[i]);
                }
                cadastradas = 1;
                break;
            case 2:
                if (!cadastradas) {
                    printf("Cadastre as cartas primeiro!\n");
                    break;
                }
                for (int i = 0; i < NUM_CARTAS; i++) {
                    exibirCarta(cartas[i], i);
                }
                break;
            case 3:
                if (!cadastradas) {
                    printf("Cadastre as cartas primeiro!\n");
                    break;
                }
                compararCartas(cartas[0], cartas[1]);
                break;
            case 4:
                if (!cadastradas) {
                    printf("Cadastre as cartas primeiro!\n");
                    break;
                }
                salvarEmArquivo(cartas[0], cartas[1]);
                break;
            case 5:
                printf("Encerrando programa.\n");
                break;
            default:
                printf("Opção inválida.\n");
        }

    } while (opcao != 5);

    return 0;
}
