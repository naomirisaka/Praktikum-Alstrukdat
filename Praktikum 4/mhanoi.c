#include "matrix.h"
#include "boolean.h"
#include <stdio.h>

void rotate(Matrix *m){
    int temp = ELMT(*m, 0, 0);
    ELMT(*m, 0, 0) = ELMT(*m, 1, 0);
    ELMT(*m, 1, 0) = ELMT(*m, 1, 1);
    ELMT(*m, 1, 1) = ELMT(*m, 0, 1);
    ELMT(*m, 0, 1) = temp;  
}

boolean check_place(Matrix *m1, Matrix *m2, int i, int j){
    return (ELMT(*m2, 0, 0) < ELMT(*m1, i, j) && 
            ELMT(*m2, 0, 1) < ELMT(*m1, i, j+1) &&
            ELMT(*m2, 1, 0) < ELMT(*m1, i+1, j) &&
            ELMT(*m2, 1, 1) < ELMT(*m1, i+1, j+1));   
}

int main(){
    Matrix m1, m2, m2_check;
    int i, j, k, n;
    long long count;
    count = 0;
    scanf("%d", &n);
    while (n < 2){
        scanf("%d", &n);
    }
    readMatrix(&m1, n, n);
    readMatrix(&m2, 2, 2);

    for (i = 0; i <= n-2 ; i++){
        for (j = 0; j <= n-2; j++){
            copyMatrix(m2, &m2_check);
            for (k = 0; k < 4; k++){
                if (check_place(&m1, &m2_check, i, j)){
                    count++;
                    break;
                }
                rotate(&m2_check);
            }
        }
    }
    printf("%lld\n", count);
    return 0;
}

