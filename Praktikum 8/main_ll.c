#include <stdio.h>
#include "listlinier.h"
#include "boolean.h"

int main(){
    List l1, l2, l3;
    int i, idx, n, val;
    CreateList(&l1);
    CreateList(&l2);
    CreateList(&l3);
    
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        scanf("%d", &val);
        insertLast(&l1, val);
    }
    if (isEmpty(l1)){
        printf("Empty list\n");
    }
    displayList(l1);
    printf("%d\n", length(l1));

    scanf("%d", &n);
    for (i = 0; i < n; i++){
        scanf("%d", &val);
        insertLast(&l2, val);
    }
    if (isEmpty(l2)){
        printf("Empty list\n");
    }
    displayList(l2);
    printf("%d\n", length(l2));

    printf("Index to get: ");
    scanf("%d", &idx);
    printf("%d\n", getElmt(l1, idx));

    printf("Index to change: ");
    scanf("%d", &idx);
    printf("New value: ");
    scanf("%d", &val);
    setElmt(&l1, idx, val);
    displayList(l1);

    printf("Value to search: ");
    scanf("%d", &val);  
    printf("%d\n", indexOf(l1, val));

    printf("Value to insert: ");
    scanf("%d", &val);
    insertFirst(&l1, val);
    displayList(l1);

    insertAt(&l1, val, idx);
    displayList(l1);

    insertLast(&l1, val);
    displayList(l1);

    deleteFirst(&l1, &val);
    displayList(l1);

    deleteAt(&l1, idx, &val);
    displayList(l1);

    deleteLast(&l1, &val);
    displayList(l1);

    l3 = concat(l1, l2);
    displayList(l3);

    return 0;
}