#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "list_circular.h"

int main() {
    List l;
    int N, i, j, val, winner, list;
    boolean first;
    Address curr, prev, deleted, next;

    CreateList(&l);
    scanf("%d", &N);
    boolean delete[N + 69];

    for (i = 1; i <= N; i++) {
        insertLast(&l, i);
        delete[i] = false;
    }

    winner = 0;
    first = 1;
    list = N;
    for (i = 0; i < N - 1; i++) {
        scanf("%d", &val);
        curr = FIRST(l);
        prev = curr;
        deleted = NEXT(curr);
        next = NEXT(deleted);
        if (val > 0 || first) { // move to the right
           val--;
        }
        val %= list;
        val += list;
        val %= list;
        
        if (val == 0){
            val = list;
        }
        
        for (j = 1; j <= val; j++){
            prev = NEXT(prev);
            deleted =  NEXT(deleted);
            next = NEXT(next);
        }

        NEXT(prev) = next;
        FIRST(l) = deleted;
        delete[INFO(deleted)] = 1;
        winner = INFO(prev);
        list--;
        first = 0;
    }

    for (i = 1; i <= N; i++){
        if (!delete[i]){
            printf("%d\n", i);
            break;
        }
    }

    return 0;
} 