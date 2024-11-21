#include "listdin.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    ListDin l1, l2, l_op;
    int n;
    ElType val, keep_val;
    int val_loc, min, max, sum_val;
    boolean plus, asc;
    CreateListDin(&l1, 10);
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
    CreateListDin(&l2, 10);
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
    printf("Jumlah kemunculan value: %d\n", countVal(l1, val));
    extremeValues(l1,&max,&min);
    printf("Min: %d\n", min);
    printf("Max: %d\n", max);
    sum_val = sumList(l1);
    printf("Total values: %d\n", sum_val);
    compressList(&l1);
    if (isFull(l1)){
        expandList(&l1,10);
    }
    insertLast(&l1, val);
    printList(l1);
    printf("\n");
    if (NEFF(l2) < (CAPACITY(l2)/2)){
        shrinkList(&l2, 5);
    }
    deleteLast(&l2, &keep_val);
    printList(l2);
    printf("\n");
    asc = true;
    sort(&l1, asc);
    printList(l1);
    printf("\n");
    asc = false;
    sort(&l2, asc);
    printList(l2);
    printf("\n");
    return 0;
}