#include <stdio.h>

const int totalTrucks = 3;

const float trucksCapacidade[] = {200.0, 150.0, 100.0}; // Capacidade de cada truck
const float precoGas[] = {5.0, 6.0, 5.5}; // Preço do litro

float getGasCost(int truckID, float capacidade) {
    if (capacidade > 0 && capacidade <= 200) {

        printf("Caminhao %d | Capacidade: %.1f | Preco: %.1f\n", 
            truckID + 1, 
            capacidade, 
            precoGas[truckID]
        );
        // Custo do abastecimento do truck atual.
        return capacidade * precoGas[truckID]; 
    } 
    else {
        printf("Capacidade invalida: %.1f\n", capacidade);
        return 0.0; // se a capacidade for inválida, retorna 0.
    }
}

float getTotalCost(int truckID, float PrevTotalCost) {
    // Caso recursivo -> 0 < 3
    if (truckID < totalTrucks) {
        // Acumula o custo do truck atual e chama a função para o próximo truck.
        PrevTotalCost += getGasCost(truckID, trucksCapacidade[truckID]);

        printf("Caminhao %d --> R$ %.2f\n", truckID + 1, PrevTotalCost);

        return getTotalCost(truckID + 1, PrevTotalCost);
    }
    // Caso base -> 3 == 3
    else {
        return PrevTotalCost; // Retorna o custo total acumulado.
    }
}

int main() {
    float total = getTotalCost(0, 0.0);
    printf("Total: R$ %.2f\n", total);
    scanf("%*c"); // Limpa o buffer do teclado
    return 0;
}
