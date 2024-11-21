#include "listdin.h"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    ListDin l, result;
    int num1, num2, i, idx1, idx2;
    CreateListDin(&l, 1000);
    readList(&l);
    scanf("%d %d", &num1, &num2);
    insertLast(&l, num1);
    insertLast(&l, num2);
    sort(&l, true);

    for (i = 0; i < NEFF(l); i++){
        if (ELMT(l,i) == num1){
            idx1 = i;
        }
        if (ELMT(l, i) == num2){
            idx2 = i;
        }
    }

    if (idx2-idx1 == 1){
        for (i = 0; i < NEFF(l); i++){
            printf("%d", ELMT(l, i));
            if (i != NEFF(l)-1){
                printf(" ");
            }
        }
        printf("\n");
    } else {
        if (idx1 % 2 == 0){
            if (idx2 % 2 == 0){
                for (i = 0; i <= idx1; i++){
                    printf("%d", ELMT(l, i));
                    printf(" ");
                }
                for (i = idx2+1; i < NEFF(l); i++){
                    printf("%d", ELMT(l, i));
                    if (i != NEFF(l)-1){
                        printf(" ");
                    }
                }
                printf("\n");
            } else {
                for (i = 0; i <= idx1; i++){
                    printf("%d", ELMT(l, i));
                    printf(" ");
                }
                for (i = idx2; i < NEFF(l); i++){
                    printf("%d", ELMT(l, i));
                    if (i != NEFF(l)-1){
                        printf(" ");
                    }
                }
                printf("\n");
            }
        } else {
            if (idx2 % 2 == 0){
                for (i = 0; i < idx1; i++){
                    printf("%d", ELMT(l, i));
                    printf(" ");
                }
                for (i = idx2+1; i < NEFF(l); i++){
                    printf("%d", ELMT(l, i));
                    if (i != NEFF(l)-1){
                        printf(" ");
                    }
                }
                printf("\n");
            } else {
                for (i = 0; i < idx1; i++){
                    printf("%d", ELMT(l, i));
                    printf(" ");
                }
                for (i = idx2; i < NEFF(l); i++){
                    printf("%d", ELMT(l, i));
                    if (i != NEFF(l)-1){
                        printf(" ");
                    }
                }
                printf("\n");
            }
        }
    }
    dealocateList(&l);
    return 0;
}