#include <stdio.h>

int main (){
    int idade, matricula;
    float altura;
    char nome[50];

    printf("Digite sua idade: \n");
    scanf("%d", &idade);

    printf("Digite sua altura:\n");
    scanf("%f", &altura);

    printf("Digite o seu nome:\n");
    scanf("%s", &nome);

    printf("Digite sua matricula: \n");
    scanf("%f", &matricula);

    printf("Nome do aluno: %s - Matricula: %d\n", nome, matricula);
    printf("Idade: %d - Altura %f", idade, altura);

    return 0;
}