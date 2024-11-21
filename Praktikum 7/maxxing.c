#include <stdio.h>
#include "prioqueue.h"

int main() {
    int n, i; 
    scanf("%d", &n);
    PrioQueue q1, q2;
    CreatePrioQueue(&q1);
    CreatePrioQueue(&q2);
    
    for (i = 0; i < n; i++) {
        int a; 
        scanf("%d", &a);
        enqueue(&q1, a);
    }

    for (i = 0; i < n; i++) {
        int b; 
        scanf("%d", &b);
        enqueue(&q2, b);
    }

    long long ans = 0;
    while (!isEmpty(q1) && HEAD(q1) != 0 && HEAD(q2) != 0){
        int a, b;
        dequeue(&q1, &a);
        dequeue(&q2, &b);
        ans += (long long)a * b;
    }

    printf("%lld\n", ans);
    return 0;
}