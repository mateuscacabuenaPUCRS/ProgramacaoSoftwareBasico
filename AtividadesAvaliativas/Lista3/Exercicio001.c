/* Exercicio001.c
Autor: Mateus Caçabuena
Finalidade: Inverter todos os bits da representação binária de um número inteiro e mostrar o valor decimal invertido.
Data: 08/05/2025 */

#include <stdio.h>

int main() {
    int num;
    scanf("%d", &num);
    printf("%d\n", ~num);
    return 0;
}
