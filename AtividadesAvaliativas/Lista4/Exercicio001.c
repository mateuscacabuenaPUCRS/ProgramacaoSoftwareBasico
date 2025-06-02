/* Exercicio007.c
Autor: Mateus Campos
Finalidade: Gerar um Diagrama de Voronoi utilizando matriz de caracteres com 5 pontos centrais definidos pelo usuário.
Data: 07/05/2025 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TOTAL_SEMENTES 5

typedef struct {
    int linha;
    int coluna;
} Semente;

int main() {
    int linhas, colunas;
    scanf("%d %d", &linhas, &colunas);

    Semente sementes[TOTAL_SEMENTES];
    for (int i = 0; i < TOTAL_SEMENTES; i++) {
        scanf("%d %d", &sementes[i].linha, &sementes[i].coluna);
    }

    char **matriz = malloc(linhas * sizeof(char*));
    for (int i = 0; i < linhas; i++) {
        matriz[i] = malloc((colunas + 1) * sizeof(char));
        for (int j = 0; j < colunas; j++) {
            matriz[i][j] = ' ';
        }
        matriz[i][colunas] = '\0';
    }

    for (int i = 0; i < TOTAL_SEMENTES; i++) {
        int x = sementes[i].linha;
        int y = sementes[i].coluna;
        if (x >= 0 && x < linhas && y >= 0 && y < colunas) {
            matriz[x][y] = '.';
        }
    }

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (matriz[i][j] == '.') continue;

            double menor = -1.0;
            int mais_proxima = -1;

            for (int k = 0; k < TOTAL_SEMENTES; k++) {
                int dx = i - sementes[k].linha;
                int dy = j - sementes[k].coluna;
                double dist = sqrt(dx * dx + dy * dy);

                if (menor < 0 || dist < menor) {
                    menor = dist;
                    mais_proxima = k;
                }
            }

            matriz[i][j] = '1' + mais_proxima;
        }
    }

    for (int i = 0; i < linhas; i++) {
        printf("%s\n", matriz[i]);
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}