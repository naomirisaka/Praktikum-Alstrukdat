#include <stdio.h>
#include "boolean.h"
#include "listrec.h"

int main(){
    List l1 = NULL, l2 = NULL, l1_rev = NULL; // init listrec
    int n, i, val, idx;

    printf("List 1\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        scanf("%d", &val);
        l1 = konsb(l1, val);
    }
    displayList(l1);
    if (isEmpty(l1)){
        printf("Empty list\n");
    } else if (isOneElmt(l1)){
        printf("List has 1 element\n");
    }
    printf("List length: %d\n", length(l1));

    printf("Middle of list 1: %d\n", getMiddle(l1));

    l1_rev = reverseList(l1);
    displayList(l1_rev);
    
    printf("Value to insert in front: ");
    scanf("%d", &val);
    displayList(konso(l1, val)); // l1 stays the same
    
    printf("Index to insert/delete at: ");
    scanf("%d", &idx);
    displayList(insertAt(l1, val, idx));

    printf("\n");
    displayList(deleteFirst(l1));

    printf("\n");
    displayList(deleteLast(l1));

    printf("\n");
    displayList(deleteAt(l1, idx));

    printf("Value to check: ");
    scanf("%d", &val);
    if (isMember(l1, val)){
        printf("Value found in list\n");
    } else {
        printf("Value not found in list\n");
    }

    List l3 = NULL, l4 = NULL;
    splitOddEven(l1, &l3, &l4);
    printf("Even list:\n");
    displayList(l3);
    printf("Odd list:\n");
    displayList(l4);

    l3 = NULL, l4 = NULL;
    printf("Index to split on: ");
    scanf("%d", &idx);
    splitOnX(l1, idx, &l3, &l4);
    printf("List before idx:\n");
    displayList(l3);
    printf("List after idx:\n");
    displayList(l4);

    printf("List 2\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        scanf("%d", &val);
        l2 = konsb(l2, val);
    }
    displayList(l2);

    printf("Concatenated list:\n");
    displayList(concat(l1, l2));

    return 0;
}