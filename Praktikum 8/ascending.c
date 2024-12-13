#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"
#include "boolean.h"

int main() {
    List l;
    int val, i;
    Address p, prev;
    CreateList(&l);

    scanf("%d", &val);
    while (val != -9999){    
        if (isEmpty(l)){
            insertFirst(&l, val);
        } else {
            p = FIRST(l);
            prev = NULL;
            i = 0;
            while (p != NULL && val > INFO(p)){
                prev = p;
                p = NEXT(p);
                i++;
            }
            
            if (prev == NULL){
                insertFirst(&l, val);
            } else if (p == NULL){
                insertLast(&l, val);
            } else {
                insertAt(&l, val, i);
            }
        }
        scanf("%d", &val);
    }

    displayList(l);
    return 0;
}