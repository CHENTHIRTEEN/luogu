#include <stdio.h>
#include <math.h>
// 判断是否是水仙花数
int f(int x){
    int sum = 0, tmp = x;
    while (x != 0) {
        sum += (int)pow(x % 10, 3);
        x /= 10;
    }
    if (sum == tmp) return 1;
    return 0;
}
int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    for (int i = a; i <= b; ++i) {
        if (f(i) == 1) printf("%d", i);
    }
    return 0;
}