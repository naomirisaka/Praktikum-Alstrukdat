#include <stdio.h>
#include "boolean.h"
#include "listrec.h"

int main(){
    List l1 = NULL, l2 = NULL; // init listrec
    int n, i, val;

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
    
    printf("Value to insert in front: ");
    scanf("%d", &val);
    displayList(konso(l1, val)); // l1 stays the same

    printf("Value to check: ");
    scanf("%d", &val);
    if (isMember(l1, val)){
        printf("Value found in list\n");
    } else {
        printf("Value not found in list\n");
    }

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