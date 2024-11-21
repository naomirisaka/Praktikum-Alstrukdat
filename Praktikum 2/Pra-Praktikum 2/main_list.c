#include "liststatik.h"
#include <stdio.h>

int main(){
    ListStatik l1, l2, l_op;
    IdxType n;
    ElType val;
    int val_loc, min, max;
    boolean plus, asc;
    readList(&l1);
    printList(l1);
    printf("\nPanjang list: %d\n", listLength(l1));
    if (isEmpty(l1)){
        printf("List kosong\n");
    } else if (isFull(l1)) {
        printf("List penuh\n");
    } else {
        printf("List tidak kosong maupun penuh\n");
    }
    printf("Index pertama list: %d\n", getFirstIdx(l1));
    printf("Index terakhir list: %d\n", getLastIdx(l1));
    printf("Index untuk dicek pada list: ");
    scanf("%d", &n); // scanf auto enter afterwards
    if (isIdxValid(l1,n)){
        printf("Index dalam kapasitas list\n");
    } else {
        printf("Index tidak valid\n");
    }
    if (isIdxEff(l1,n)){
        printf("Index efektif\n");
    } else {
        printf("Index tidak efektif\n");
    }
    readList(&l2); // make it the same size as l1
    printList(l2);
    plus = true;
    l_op = plusMinusList(l1,l2,plus);
    printf("\nL1 + L2 = ");
    printList(l_op);
    plus = false;
    l_op = plusMinusList(l1,l2,plus);
    printf("\nL1 - L2 = ");
    printList(l_op);
    printf("\n");
    if (isListEqual(l1,l2)){
        printf("List equal\n");
    } else {
        printf("List tidak equal\n");
    }
    printf("Value yang ingin dicari/ditambah: ");
    scanf("%d", &val);
    printf("Index ke: ");
    scanf("%d", &n);
    val_loc = indexOf(l1, val);
    printf("Lokasi value: %d\n", val_loc);
    extremeValues(l1,&max,&min);
    printf("Min: %d\n", min);
    printf("Max: %d\n", max);
    insertFirst(&l1, val);
    printList(l1);
    printf("\n");
    insertAt(&l1, val, n);
    printList(l1);
    printf("\n");
    insertLast(&l1, val);
    printList(l1);
    printf("\n");
    deleteFirst(&l1, &val);
    printList(l1);
    printf("\n");
    deleteAt(&l1, &val, n);
    printList(l1);
    printf("\n");
    deleteLast(&l1, &val);
    printList(l1);
    printf("\n");
    asc = true;
    sortList(&l1, asc);
    printList(l1);
    printf("\n");
    asc = false;
    sortList(&l2, asc);
    printList(l2);
    printf("\n");
    return 0;
}