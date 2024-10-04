#include <stdio.h>
#include <math.h>

int main(){
    int n, a, b, count, i, bef_1, bef_2;
    count = 0;
    scanf("%d %d %d", &n, &a, &b);
    count = count + a + b;
    bef_1 = a;
    bef_2 = b;
    for (i = 3; i <= n; i++){
        count = bef_1 + bef_2;
        bef_1 = bef_2;
        bef_2 = count;
    }
    printf("%d", count);
    printf("\n");
    return 0;
}