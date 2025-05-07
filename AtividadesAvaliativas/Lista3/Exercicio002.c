#include <stdio.h>

int main() {
    int g, r, b;
    scanf("%d %d %d", &g, &r, &b);
    int color = (g & 0xE0) | ((r & 0xE0) >> 3) | ((b & 0xC0) >> 6);
    printf("%d\n", color);
    return 0;
}
