#include "queue.h"
#include "boolean.h"
#include <stdio.h>

int main(){
    Queue q;
    int i, n, val;
    CreateQueue(&q);
    scanf("%d", &n);
    i = 0;
    while ((i < n) && (i < CAPACITY-1)){
        int el;
        scanf("%d", &el);
        enqueue(&q, el);
        i++;
    }
    displayQueue(q);
    if (!isEmpty(q)){
        dequeue(&q, &val);
        printf("Dequeued val: %d\n", val);
    }
    
    if (isEmpty(q)){
        printf("Empty queue\n");
    } else if (isFull(q)){
        printf("Full queue\n");
    } else {
        printf("Queue length: %d\n", length(q));
    }
    displayQueue(q);
    return 0;
}