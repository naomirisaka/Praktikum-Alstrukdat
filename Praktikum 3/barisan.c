#include "listdin.h"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    ListDin l;
    int i, j, k, n, num, count;
    count = 0;
    CreateListDin(&l, 1000);
    scanf("%d", &n);
    while (n < 0 || n > CAPACITY(l)){
      scanf("%d", &n);
    }    
    for (i = 0; i < n; i++){
        scanf("%d", &num);
        if (isEmpty(l)){
            insertLast(&l, num);
        } else {
            j = listLength(l)-1;
            if (num >= ELMT(l, getLastIdx(l))){
                insertLast(&l, num);
            } else {
                while (j >= 0 && ELMT(l, j) > num){ // bcs bisa aja harus dishift ke paling depan
                    j--;
                }
                for (k = listLength(l); k > j + 1; k--){ // bcs elmt(l, k) shouldn't be shifted
                    if (listLength(l) < CAPACITY(l)){
                        ELMT(l, k) = ELMT(l, k-1);
                    }
                    count++;
                }
                ELMT(l, k) = num;
                NEFF(l)++;
            }
        }
    }
    printf("%d\n", count);
    return 0;
}