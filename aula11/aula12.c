#include <stdio.h>

int main(){
    int idade, matricula;
    float altura;
    char nome[50];

    printf("Digite sua idade: \n");
    scanf("%d", &idade);

    printf("Digite sua altura: \n");
    scanf("%f" , &altura);
    
    printf("Digite se nome: \n");
    scanf("%s", &nome);

    printf("Digite sua matricula \n");
    scanf("%d", &matricula);

    printf("Nome do aluno: %s - Matricula: %d\n", nome, matricula);
    printf("Idade: %d - Altura: %f", idade, altura); 

    return 0;


/*
printf("%formato1 %formato2 %formato3", variavel1, variavel2, variavel3)

%d: Imprime um inteiro no formato decimal.
%i: Equivalente a %d.
%f: Imprime um número de ponto fluturate no formato padrão.
%e: Imprime um número de ponto flutuante na notação científica.
%c: Imprime um único caracteres.altura
%s: Imprime uma cadeia (string) de caracateres.
*/


}
