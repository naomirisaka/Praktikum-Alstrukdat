#include "matrix.h"
#include "boolean.h"
#include <stdio.h>

#define MOD 1000000007

int main(){
    Matrix m1;
    int i, j, k, n;
    long long sum;
    scanf("%d", &n);
    while (n < 2 || n > 100){
        scanf("%d", &n);
    }
    readMatrix(&m1, n, n);
    n = getLastIdxRow(m1)+1;
    ROW_EFF(m1) = n;
    COL_EFF(m1) = n;
    
    
    sum = 0;
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            if (ELMT(m1, i, j) > 0){
                for (k = 0; k < n; k++){
                    if (k != i){
                        sum = (sum + ELMT (m1, k, j)) % MOD;
                    }
                    if (k != j){
                        sum = (sum + ELMT(m1, i, k)) % MOD;
                    }
                }
            }
        }
    }

    printf("%lld\n", sum);
    return 0;
}