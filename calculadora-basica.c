#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

double calcular(double *ptrA, double *ptrB, char operador) {
    // Declaração de variáveis
    double result;

    printf("\nResultado:\n"); // Mensagem de resultado

    // Operações matemáticas
    switch (operador) {
        case '+':
            result = *ptrA + *ptrB;
            printf("%.2f + %.2f = %.2f \n", *ptrA, *ptrB, result);
            break;
        case '-':
            result = *ptrA - *ptrB;
            printf("%.2f - %.2f = %.2f \n", *ptrA, *ptrB, result);
            break;
        case '*':
            result = *ptrA * *ptrB;
            printf("%.2f * %.2f = %.2f \n", *ptrA, *ptrB, result);
            break;
        case '/':
            result = *ptrA / *ptrB;
            printf("%.2f / %.2f = %.2f \n", *ptrA, *ptrB, result);
            break;
        case '^':
            result = pow(*ptrA, *ptrB);
            printf("%.2f ^ %.2f = %.2f \n", *ptrA, *ptrB, result);
            break;
        case 'v':
            result = pow(*ptrA, 1.00 / *ptrB); // O inverso da potencia é a raiz, então usamos 1.00 / *ptrB para calcular a raiz de *ptrA
            printf("Raiz %.2fa de %.2f = %.2f \n", *ptrB, *ptrA, result);
            break;
        default:
            printf("Operador invalido! \n");
    };

    printf("\n"); // Quebra de linha para melhor visualização

    // Armazenando o resultado pra usar de A em outro calculo
    *ptrA = result;
    return result;
}

int main () {

    printf("Calculadora\n");

    // Estado de controle do loop principal
    int continuar = true;
    int clearA = 2;
    int *ptrClearA = &clearA;

    // variáveis
    double a, b;
    double *ptrA = &a;
    double *ptrB = &b;

    char operador;
    
    while (continuar == true) {

        // Lendo o primeiro número
        printf("Valor de A: %.2f\n", *ptrA);

        // Lendo a decisão do usuário sobre limpar A
        printf("(0 = sair | 1 = continuar | 2 = limpar e continuar): ");
        scanf("%d", ptrClearA); 

        // Limpa o valor de B a cada iteração
           *ptrB = 0;

        // Pergunta se o valor de A deve ser limpo ou não
        switch (*ptrClearA) {
            case 0:
                printf("Saindo...\n");
                continuar = false;
                return 0;
            case 1:
                //printf("Continuando sem limpar A...\n");
                break;
            default:
                //printf("Limpando A e continuando...\n");
                *ptrA = 0;
                printf("Digite o primeiro numero: ");
                scanf("%lf", ptrA);
                break;
        }
        
        // Lendo o operador
        printf("Digite o operador (+, -, *, /, ^, v): ");
        scanf(" %c", &operador);

        // Lendo o segundo número
        printf("Digite o segundo numero: ");
        scanf("%lf", ptrB); 

        printf("\n"); // Quebra de linha para melhor visualização

        // Valida se os ponteiros não são nulos
        calcular(ptrA, ptrB, operador);
    };

    // Fim
    return 0;
}
