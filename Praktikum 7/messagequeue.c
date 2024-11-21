#include <stdio.h>
#include "queue.h"

int main() {
    int n;
    Queue q;
    scanf("%d", &n);
    CreateQueue(&q);
    for (int i = 0; i < n; ++i) {
        int op;
        scanf("%d", &op);

        // Kerjakan keempat tipe query disini
        if (op == 1) {
            int x;
            scanf("%d", &x);
            if (isFull(q)){
                printf("Queue Penuh\n");
            } else {
                enqueue(&q, x);
                printf("Enqueue %d Berhasil\n", x);
            }
        } else if (op == 2) {
            if (isEmpty(q)){
                printf("Queue Kosong\n");
            } else {
                int x;
                dequeue(&q, &x);
                printf("Dequeue %d Berhasil\n", x);
            }
        } else if (op == 3) {
            if (isEmpty(q)){
                printf("Queue Kosong\n");
            } else {
                printf("Elemen Awal Queue adalah %d\n", HEAD(q));
            }
        } else if (op == 4) {
            printf("Ukuran Queue saat ini adalah %d\n", length(q));
        }
    }

    // Display Queue disini
    displayQueue(q);
    return 0;
}