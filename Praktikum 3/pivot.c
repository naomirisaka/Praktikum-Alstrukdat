#include "listdin.h"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    ListDin l;
    int i, n, count;
    CreateListDin(&l, 1000000);
    readList(&l);
    n = listLength(l);
    NEFF(l) = n;
    int left_max[n], right_min[n];

    left_max[0] = ELMT(l, 0);
    for (i = 1; i < n; i++){    
        if (ELMT(l,i) > left_max[i-1]){
            left_max[i] = ELMT(l,i);
        } else {
            left_max[i] = left_max[i-1];
        }
    }

    right_min[n-1]= ELMT(l, n-1);
    for (i = n-2; i >= 0; i--){
        if (ELMT(l,i) <= right_min[i+1]){
            right_min[i] = ELMT(l,i);
        } else {
            right_min[i] = right_min[i+1];
        }
    }
    count = 0;
    for (i = 0; i < n; i++){
        if ((i == 0 || left_max[i-1] <= ELMT(l,i)) && (i == n-1 || right_min[i+1] > ELMT(l,i))){
            count++;
        }
    }

    printf("%d\n", count);
    return 0;
}