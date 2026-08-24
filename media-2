#include <stdio.h>
#include <stdbool.h>

#define mediaMinima 70.0

int main() {

    printf("\nMedia\n");

    // Loopar
    int continuar = true;
    int debounce = 0; // Evita que while/scanf() percam o controle

    // Declarações
    int isApproved;
    double nota1, nota2, media;

    int *ptrIsApproved;
    ptrIsApproved = &isApproved;

    double *ptrNota1, *ptrNota2, *ptrMedia;
    ptrNota1 = &nota1;
    ptrNota2 = &nota2;
    ptrMedia = &media;

    while (continuar && debounce < 50)
    {
        debounce++; // debounce += 1;

        printf("\nEncerrar? (0.Sim | 1.Nao)\n");
        scanf("%d", &continuar);

        // Valida escolha do usuário
        switch (continuar)
        {
        case 0:
            // Fim
            printf("\nFim do programa.\n");
            return 0;
        default: // Continua normalmente
            break;
        }

        // Entrada de dados
        printf("\nMedia minima para aprovacao: %.1lf\n", mediaMinima);

        printf("\nDigite a Nota 1: ");
        scanf("%lf", ptrNota1);

        printf("\nDigite a Nota 2: ");
        scanf("%lf", ptrNota2);

        // Processa dados
        *ptrMedia = (*ptrNota1 + *ptrNota2) / 2.0;
        printf("\nSua media foi = %.1lf \n", *ptrMedia);

        *ptrIsApproved = *ptrMedia >= mediaMinima;
        printf("%d", *ptrIsApproved);

        /*
        if (*ptrIsApproved)
        {
            printf("\nParabens! Voce esta aprovado!\n");
        }
        else
        {
            printf("\nVoce nao obteve uma media suficiente. Continue tentando.\n");
        }
        */
        
        switch (*ptrIsApproved)
        {
        case 0: /* Se falso (reprovado) */
            printf("\nVoce nao obteve uma media suficiente. Continue tentando.\n");
            break;
        
        default: // Se true (aprovado)
            printf("\nParabens! Voce esta aprovado!\n");
            break;
        }

    }

    // Fim
    printf("\nFim do programa.\n");
    return 0;
}
