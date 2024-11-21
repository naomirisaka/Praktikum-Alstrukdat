#include "liststatik.h"
#include "boolean.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main(){
    ListStatik l, l_count;
    int min, max, max_1, max_2, i_max_1, i_max_2;
    IdxType i, j;
    readList(&l);
    if (listLength(l) < 2){
        printf("Tidak ada elemen kedua yang paling sering muncul\n");
        return 0;
    } else {
        CreateListStatik(&l_count);
        extremeValues(l, &max, &min);
        
        for (i = 0; i < (abs(min) + abs(max) + 1); i++){
            ELMT(l_count, i) = 0;
        }

        for (j = 0; j < listLength(l); j++){
            ELMT(l_count, ELMT(l, j) + abs(min))++; 
        }

        max_1 = 0;
        max_2 = 0;
        i_max_1 = -1;
        i_max_2 = -1;

        for (i = 0; i < listLength(l_count); i++){
            if (ELMT(l_count, i) > max_1){
                max_2 = max_1;
                i_max_2 = i_max_1;
                max_1 = ELMT(l_count, i);
                i_max_1 = i;
            } else if (ELMT(l_count, i) > max_2 && ELMT(l_count, i) < max_1){
                max_2 = ELMT(l_count, i);
                i_max_2 = i;
            }
        }
        
        if (i_max_2 != -1){
            printf("%d\n", i_max_2 - abs(min)); 
        } else {
            printf("Tidak ada elemen kedua yang paling sering muncul\n");
        }
        return 0;
    }
}
