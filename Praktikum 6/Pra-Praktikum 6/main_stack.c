#include <stdio.h>
#include "boolean.h"
#include "stack.h"

int main(){
    Stack s;
    int i, n, x;
    CreateEmpty(&s);
    printf("Amount of var: ");
    scanf("%d", &n);
    i = 0;
    while (i < n){
        scanf("%d", &x);
        Push(&s, x);
        i++;
    }
    if (IsFull(s)){
        printf("Full stack\n");
    }
    if (!IsEmpty(s)){
        Pop(&s, &x);
        printf("Top: %d\n", x);
    }
    return 0;
}