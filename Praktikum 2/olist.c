#include "liststatik.h"
#include "boolean.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main(){
    ListStatik l, l_unique;
    int count;
    IdxType i, j;
    readList(&l);
    CreateListStatik(&l_unique);
    for (i = 0; i < listLength(l); i++){
        for (j = 0; j < i; j++){
            if (ELMT(l,i) == ELMT(l,j)){
                break;
            }
        }
        if (i == j){
            insertLast(&l_unique, ELMT(l,i));
        }
    }

    printList(l_unique);
    printf("\n");

    for (i = 0; i < listLength(l_unique); i++){
        count = 0;
        for (j = 0; j < listLength(l); j++){
            if (ELMT(l_unique,i) == ELMT(l,j)){
                count++;
            }
        }
        printf("%d %d\n", ELMT(l_unique,i), count);
    }
}