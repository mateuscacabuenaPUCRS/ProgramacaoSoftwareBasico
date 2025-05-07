#include <stdio.h>

int main() {
    int i, byte;
    for (i = 0; i < 8; i++) {
        scanf("%d", &byte);
        for (int j = 7; j >= 0; j--) {
            if ((byte >> j) & 1)
                printf("X");
            else
                printf(".");
        }
        printf("\n");
    }
    return 0;
}
