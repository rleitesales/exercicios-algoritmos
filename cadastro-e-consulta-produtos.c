#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

//#define true 1==1   // mesma coisa que true:  1
//#define false 1==2 //  mesma coisa que false: 0

#define LIMITE_PRDTS 5
#define PRDTS_NOME_TAMANHO 31

enum Options {    
    SAIR,       // 1º Membro vale 0 por padrão
    CADASTRAR,  // Vale 1
    CONSULTAR,  // Vale 2 e etc...
    PARADO, 
};

struct Produto {
    char nome[PRDTS_NOME_TAMANHO];
    float preco;
};

struct Estoque {
    struct Produto lista[LIMITE_PRDTS]; // array com espaço para até 10 prdts
    int total; // qtde atual de prdts cadastrados
    // Controla qual index acessar
};

int main () { 
    
    printf("\n|Produtos|\n");

    // Estado do programa
    bool continuar = true;
    int escolha = PARADO;
    int debounce = false;

    // Salva valores
    struct Estoque meuEstoque;
    meuEstoque.total = 0; // Inicia com 0 prdts cadastrados

    // Loop de execução
    while (continuar && debounce < 50)
    {
        debounce++;

        printf("\nO que deseja?\n| %d.Sair | %d.Cadastrar produto | %d.Consultar produto |\n", SAIR, CADASTRAR, CONSULTAR);
        scanf("%d", &escolha);

        switch (escolha)
        {
            case SAIR:
                printf("\nEncerrando...\n");
                return 0;

            case CADASTRAR:
                if (meuEstoque.total >= LIMITE_PRDTS)
                {
                    printf("\nEstoque cheio!");
                    printf("\nO limite maximo de %d produtos foi atingido.\n",
                    LIMITE_PRDTS);
                } 
                else {
                    struct Produto novoPrdt;

                    printf("\nDigite o nome do produto: ");
                    scanf("%30s", novoPrdt.nome); // limita a leitura do tamanho do buffer
                    
                    //char inp[31];
                    //scanf("%30s", &inp); // limita a leitura do tamanho do buffer
                    //strncpy(new.nome, inp, sizeof(new.nome)-1);
                    //new.nome[sizeof(new.nome)-1] = '\0';

                    printf("\nDigite o preco: ");
                    scanf("%f", &novoPrdt.preco);

                    // Salvar valores
                    meuEstoque.lista[meuEstoque.total] = novoPrdt;
                    meuEstoque.total++;

                    printf("\nNovo produto cadastrado:\n(%s | R$ %.2f )\n", 
                        novoPrdt.nome, 
                        novoPrdt.preco
                    );
                }
                break;

            case CONSULTAR:
                if (meuEstoque.total == 0)
                {
                    printf("\nNenhum item foi cadastrado.\n");
                }
                else
                {
                    printf("\n--CONSULTA DE ESTOQUE--\n");

                    for (int i = 0; i < meuEstoque.total; i++)
                    {
                        printf("[%d] Nome: %s | Preco: R$%.2f \n", 
                            i+1, 
                            meuEstoque.lista[i].nome, 
                            meuEstoque.lista[i].preco);
                    }
                }
                break;

            default:
                printf("\nOpcao invalida. Tente novamente.\n");
                break;
        }
    };
    
    // Fim
    return 0;
}
