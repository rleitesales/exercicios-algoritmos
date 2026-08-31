//Estruturas-de-Repeticao-Condicional
#include <stdio.h>

int main() {
    int n;
    int soma = 0;

    printf("Digite um numero inteiro para somar (0.Sair):\n> ");
    scanf("%d", &n);

    while (n != 0) {
        soma += n;

        printf("Digite um numero inteiro para somar (0.Sair):\n> ");
        scanf("%d", &n);
    }
    
    printf("\nO resultado final eh %d.\n", soma);
    printf("Programa encerrado.\n");
    return 0;
}
