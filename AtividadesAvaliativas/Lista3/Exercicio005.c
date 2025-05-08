/* Exercicio005.c
Autor: Mateus Caçabuena
Finalidade: Contar e mostrar quantos bits 0 há à direita do bit 1 mais significativo de um número inteiro.
Data: 08/05/2025 */

#include <stdio.h>

int main() {
    unsigned int num;
    int count = 0, flag = 0;
    scanf("%u", &num);
    if (num == 0) {
        printf("0\n");
        return 0;
    }
    for (int i = 31; i >= 0; i--) {
        if ((num >> i) & 1) {
            flag = 1;
        } else if (flag) {
            count++;
        }
    }
    printf("%d\n", count);
    return 0;
}
