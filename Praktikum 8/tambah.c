#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"
#include "boolean.h"

int main(){
    List l1, l2, result;
    int val, carry, sum;
    Address p, p1, p2;

    CreateList(&l1);
    CreateList(&l2);
    CreateList(&result);

    scanf("%d", &val);
    while (val != -1){    
        insertFirst(&l1, val);
        scanf("%d", &val);
    }

    scanf("%d", &val);
    while (val != -1){    
        insertFirst(&l2, val);
        scanf("%d", &val);
    }

    p1 = FIRST(l1);
    p2 = FIRST(l2);
    carry = 0;

    while (p1 != NULL || p2 != NULL || carry > 0) {
        sum = carry;
        if (p1 != NULL) {
            sum += INFO(p1);
            p1 = NEXT(p1);
        }
        if (p2 != NULL) {
            sum += INFO(p2);
            p2 = NEXT(p2);
        }
        insertFirst(&result, sum % 10);
        carry = sum / 10;
    }

    if (isEmpty(result)){   
        printf("0");
    } else {
        p = FIRST(result);
        while (p != NULL){
            printf("%d", INFO(p));
            p = NEXT(p);
            if (p != NULL){
                printf(" ");
            }
        }
    }
    printf("\n");
    return 0;
}