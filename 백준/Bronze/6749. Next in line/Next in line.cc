#include <stdio.h>

int main() {
    int a, b, differ;
    scanf("%d %d", &a, &b);
    differ = b - a;
    printf("%d", b + differ);
    return 0;
}