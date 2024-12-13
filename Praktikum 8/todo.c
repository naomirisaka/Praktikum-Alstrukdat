#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"
#include "boolean.h"

int main(){
    List l;
    char op;
    int val;
    CreateList(&l);

    do {
        scanf(" %c", &op);
        if (op == 'P'){
            scanf(" %d", &val);
            insertFirst(&l, val);
        } else if (op == 'I'){
            scanf(" %d", &val);
            insertLast(&l, val);
        } else if (op == 'D'){
            scanf(" %d", &val);
            int idx = indexOf(l, val);
            if (idx != IDX_UNDEF){
                deleteAt(&l, idx, &val);
            }
        } else if (op == 'C'){
            if (!isEmpty(l)){
                deleteFirst(&l, &val);
            }
        }
    } while (op != 'X');
    displayList(l);
    return 0;
}
