#include <stdio.h>

int main()
{
    double n1, n2, n3;
    double soma, subtr, mult, divis;
    
    // Entrada de dados
    printf("Digite 3 numeros (termos 'A', 'B' e 'C'):\n> ");
    scanf("%lf", &n1);
    scanf("%lf", &n2);
    scanf("%lf", &n3);
    
    // 1. Operadores Aritméticos
    soma = n1 + n2 + n3;
    subtr = n1 - n2 - n3;
    mult = n1 * n2 * n3;
    
    printf("\nSoma: %.2lf \n", soma);
    printf("Subtracao: %.2lf \n", subtr);
    printf("Multiplicacao: %.2lf \n", mult);
    
    // Evitar divisão por 0.
    if (n2 != 0 && n3 != 0) {
        divis = n1 / n2 / n3;
        printf("Divisao: %.2lf \n\n", divis);
    }
    else
    {
        printf("Nao foi possivel calcular: Houve divisao por 0.\n\n");
    }
    
    // 2. Operadores Relacionais
    
    // A > B ?
    if (n1 > n2) 
    {
        printf("'A' eh maior que 'B'.\n [%.2lf > %.2lf]\n\n", n1, n2);
    } 
    else 
    {
        printf("'A' nao eh maior que 'B'.\n [%.2lf <= %.2lf]\n\n", n1, n2);
    }
    
    // B < C ?
    if (n2 < n3) 
    {
        printf("'B' eh menor que 'C'.\n [%.2lf < %.2lf]\n\n", n2, n3);
    }
    else
    {
        printf("'B' nao eh menor que 'C'.\n [%.2lf >= %.2lf]\n\n", n2, n3);
    }
    
    // A > 0 && B % 2 == 0      --> A é positivo e B é Par?
    if ( (n1 > 0) && ((int)n2 % 2 == 0) )
    {
        printf("Sucesso!\n'A' eh POSITIVO e 'B' eh PAR.\n [%.2lf > 0 && %.2lf %% 2 == 0]\n", n1, n2);
    }
    else
    {
        printf("Para atender as condicoes especiais, os termos A e B devem, respectivamente, ser POSITIVO e PAR.\n");
    }
    
    // Fim do programa.
    printf("\n\nFim do programa.\n");
    return 0;
}
