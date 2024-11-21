#include "matrix.h"
#include "boolean.h" // row cap n col cap is 1000
#include <stdio.h>

#define MOD 1000000007

int main() {
    Matrix m1, ways;
    int i, j, n;
    scanf("%d", &n);
    
    readMatrix(&m1, n, n);
    createMatrix(n, n, &ways);

    if (ELMT(m1, 0, 0) == 1) {
        printf("0\n");
        return 0;
    }
    
    ELMT(ways, 0, 0) = 1;

    for (j = 1; j < n; j++) {
        ELMT(ways, 0, j) = (ELMT(m1, 0, j) == 1) ? 0 : ELMT(ways, 0, j - 1);
    }

    for (i = 1; i < n; i++) {
        ELMT(ways, i, 0) = (ELMT(m1, i, 0) == 1) ? 0 : ELMT(ways, i - 1, 0);
    }

    for (i = 1; i < n; i++) {
        for (j = 1; j < n; j++) {
            if (ELMT(m1, i, j) == 1) {
                ELMT(ways, i, j) = 0;
            } else {
                ELMT(ways, i, j) = (ELMT(ways, i - 1, j) + ELMT(ways, i, j - 1)) % MOD;
            }
        }
    }

    printf("%lld\n", ELMT(ways, n - 1, n - 1));
    return 0;
}