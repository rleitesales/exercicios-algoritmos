#include <stdio.h>

#define true 1
#define false 0

#define MAX_GAS 100
#define MIN_GAS 0
#define GAS_REGEN_RATE 25
#define GAS_DRAIN_RATE 5

#define DESTINO 29
// Tipos de climas
enum Climas {
    NORMAL,
    TEMPESTADE_SOLAR,
};
// Estados da Nave
enum NaveStates {
    DEFAULT = 10,
    SAFE_PROTOCOL = 50,
};

// Verifica o nível de combustível e retorna se é necessário realizar um abastecimento.
int haveGas(int gas) {
    printf("\nVerificando nivel do combustivel...\n[%d+/+] restante\n", 
        gas
    );

    if (gas < 20)
    {
        printf("Alerta! Baixo nivel de combustivel!\n");
        return 0; // Gasolina Low-Level
    } 
    else 
    {
        printf("Sucesso! Combustivel OK.\n");
        return 1; // Gasolina OK
    }
}

// Verifica se a rota da nave está corretamente alinhada com o destino e retorna se é necessário recalibra-la.
int isNaveDir(int destino, int rota) {
    printf("\nVerificando rota atual da nave...\nRota: [%d] | Destino: [%d]\n", 
        rota, 
        destino
    );

    if (rota != destino) 
    {
        printf("Atencao! Houve um desvio de rota.\n");
        return 0;
    }
    else {
        printf("A rota esta calibrada.\n");
        return 1;
    }
}

// Verifica as condições "meteorológicas" do ambiente e retorna se é necessário ativar o protocolo de proteção.
int checkTempestade(int clima) {
    printf("\nProcurando por tempestades solares...\n");

    if (clima == TEMPESTADE_SOLAR) {
        printf("AVISO! Uma Tempestade Solar foi detectada!\n");
        return 1;
    }
    else if (clima == NORMAL)
    {
        printf("Nenhuma tempestade solar foi detectada.");
        return 0;
    }
    else {
        printf("Algo impediu a verificacao.\n");
        return 0;
    }
}

int main() {

    // Declarações
    int gas = 0;    // MAX_GAS;  // Gasolina
    int *pGas;      // Ponteiro -- Conteúdo
    pGas = &gas;    // Ponteiro -- Endereço na RAM

    int destino = DESTINO;  // Alvo da nave
    int *pDestino;
    pDestino = &destino;

    int rota = 11;          // Direção do movimento da nave
    int *pRota;
    pRota = &rota;

    int clima = NORMAL;         // Tempestade Solar: Guarda qual é o clima atual
    int *pClima;
    pClima = &clima;

    int currNavStt = DEFAULT;   // Tempestade Solar: Guarda o modo ativo da nave
    int *pCurrNavStt;
    pCurrNavStt = &currNavStt;

    // INICIO
    printf("\n|Nave|\n");

    // Tem gasolina suficiente?
    if (!haveGas(*pGas))
    { // Reabasteça!
        for (int i = *pGas; i < MAX_GAS; i+= GAS_REGEN_RATE)
        {
            *pGas += GAS_REGEN_RATE;
            printf("Reabastecendo... [%d+/+]\n", *pGas);

            if (*pGas > MAX_GAS) { *pGas = MAX_GAS; }
        }
        printf("Reabastecimento completo!\n");
    }
    // Está dentro da rota correta?
    if (!isNaveDir(*pDestino, *pRota))
    { // Corrija a rota!
        printf("Recalculando rota...");
        *pRota = *pDestino;
        printf("Correcao de rota concluida com sucesso!\n");
    }
    // Há alguma tempestade solar?
    if (checkTempestade(*pClima)) 
    { // Ative o protocolo de segurança contra tempestades solares!
        printf("Ativando protocolo de Protecao...\n");
        *pCurrNavStt = SAFE_PROTOCOL;
        printf("Protocolo de Protecao ativado!\n");
    }
    else {
        printf("Desativando protocolo de Protecao...\n");
        *pCurrNavStt = DEFAULT;
        printf("Protocolo de Protecao desativado!\n");
    }

    // Fim do programa!
    printf("\nA manutencao da nave esta completa!\n");
    return 0;
}
