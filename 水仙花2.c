#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    for (int i = a / 100; i <= b / 100; i++) {
        for (int j = 0; j <= 9; ++j) {
            for (int k = 0; k <= 9; ++k) {
                int num = i * i * i + j * j * j + k * k * k;
                if (num >= a && num <= b) printf("%d ", num);
            }
        }
    }
    return 0;
}