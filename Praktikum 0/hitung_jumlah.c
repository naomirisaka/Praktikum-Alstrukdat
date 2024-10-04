#include <stdio.h>
#include <math.h>

int main(){
    int n, k, a_i, total, i; // harus declare type outside of loop
    total = 0;
    scanf ("%d %d", &n, &k);
    for (i = 0; i < n; i++){
        scanf("%d", &a_i);
        if (a_i % k != 0){
            total += a_i;
        }
    }
    printf("%d\n", total);
}