#include <stdio.h>
#include "list_circular.h"
#include "boolean.h"

int main(){
    List l;
    int i, idx, n, val;
    CreateList(&l);
    
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        scanf("%d", &val);
        insertLast(&l, val);
    }
    displayList(l);
    printf("\n");

    if (isEmpty(l)){
        printf("Empty list\n");
    }

    printf("Value to search: ");
    scanf("%d", &val);  
    if (search(l, val) != NULL){
        printf("Found\n");
        printf("Address: %p\n", search(l, val));
        if (addrSearch(l, search(l, val))){
            printf("Address of value is found\n");
        }
    } else {
        printf("Not found\n");
    }

    printf("Value to insert: ");
    scanf("%d", &val);
    insertFirst(&l, val);
    displayList(l);
    printf("\n");

    insertLast(&l, val);
    displayList(l);
    printf("\n");

    deleteFirst(&l, &val);
    displayList(l);
    printf("\n");

    deleteLast(&l, &val);
    displayList(l);
    printf("\n");

    return 0;
}