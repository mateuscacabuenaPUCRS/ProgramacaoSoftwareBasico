#include <stdio.h>

int main() {
    int color;
    scanf("%d", &color);
    int g = (color & 0xE0);
    int r = (color & 0x1C) << 3;
    int b = (color & 0x03) << 6;
    printf("%d %d %d\n", g, r, b);
    return 0;
}
