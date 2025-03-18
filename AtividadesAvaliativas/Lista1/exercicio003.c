#include <stdio.h>

void quantidadeDeMoedas(unsigned r, unsigned *m100, unsigned *m50, unsigned *m25, unsigned *m10, unsigned *m5, unsigned *m1) {
    *m100 = r / 100;
    r %= 100;

    *m50 = r / 50;
    r %= 50;

    *m25 = r / 25;
    r %= 25;

    *m10 = r / 10;
    r %= 10;

    *m5 = r / 5;
    r %= 5;

    *m1 = r;
}

int main() {
    unsigned r, m100, m50, m25, m10, m5, m1;
    
    scanf("%u", &r);
    quantidadeDeMoedas(r, &m100, &m50, &m25, &m10, &m5, &m1);
    
    printf("%u %u %u %u %u %u\n", m100, m50, m25, m10, m5, m1);
    
    return 0;
}
