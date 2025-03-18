#include <stdio.h>

#define MAX 100

int conta_repetidos(int *vet, int tam) {
    int contagem[MAX] = {0};
    int repetidos = 0;

    for (int i = 0; i < tam; i++) {
        contagem[vet[i]]++;
    }

    for (int i = 0; i < MAX; i++) {
        if (contagem[i] > 1) {
            repetidos++;
        }
    }

    return repetidos;
}

int main() {
    int vet[MAX], tam;
    
    scanf("%d", &tam);
    if (tam > MAX) return 1;

    for (int i = 0; i < tam; i++)
        scanf("%d", &vet[i]);

    printf("%d\n", conta_repetidos(vet, tam));

    return 0;
}
