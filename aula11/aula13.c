#include <stdio.h>

int main (){
    int idade;
    float altura;
    char opcao;
    char nome[20];
    
    printf("Digite sua idade:");
    scanf("%d", &idade);
    printf("A idade é: %d\n", idade);

    printf("Digite a sua altura:");
    scanf("%f", &altura);
    printf("A altura é %f\n", altura);

    printf("Digite se nome:");
    scanf("%s", nome);
    printf("O nome é: %s\n", nome);

    printf("Digite a opcao:");
    scanf(" %c", &opcao);
    printf("o nome é: %c", opcao);

    
    
    // sintaxe scanf
    // scanf("formato1" "formato2, &variavel1, variavel2...");







}