#include "liststatik.h"
#include "boolean.h"
#include <stdio.h>
#include <math.h>
#include <string.h>

int main(){
    ListStatik l,l_p;
    IdxType i;
    int length, add, sum;

    readList(&l);
    if (listLength(l) == 0){
        return -1;
    }

    length = listLength(l);
    add = 1;
    CreateListStatik(&l_p);
    for (i = length-1; i >= 0; i--){
        sum = ELMT(l,i) + add;
        ELMT (l_p, i) = sum % 10;
        add = sum / 10;
    }

    if (add > 0){
        for (i = length; i > 0; i--){
            ELMT(l_p, i) = ELMT(l_p,i-1);
        }
        ELMT(l_p, 0) = add;
    }
    
    for (i = 0; i < listLength(l_p); i++){
        printf("%d", ELMT(l_p, i));
        if (i != listLength(l_p)-1){
            printf(" ");
        } else {
            printf("\n");
        }
    }
    return 0;
}