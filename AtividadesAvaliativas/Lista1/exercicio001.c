#include <stdio.h>

void hms(int seg, int *h, int *m, int *s) {
    *h = seg / 3600;
    *m = (seg % 3600) / 60;
    *s = seg % 60;
}

int main() {
    int seg, h, m, s;
    scanf("%u", &seg);
    hms(seg, &h, &m, &s);
    printf("%u %u %u\n", h, m, s);
    return 0;
}

