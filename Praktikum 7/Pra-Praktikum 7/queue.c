#include "queue.h"
#include "boolean.h"
#include <stdio.h>

/* *** Kreator *** */
void CreateQueue(Queue *q){
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

/* ********* Prototype ********* */
boolean isEmpty(Queue q){
/* Mengirim true jika q kosong: lihat definisi di atas */
    return (IDX_HEAD(q) == IDX_UNDEF && IDX_TAIL(q) == IDX_UNDEF);
}
boolean isFull(Queue q){
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/
    return ((IDX_TAIL(q) + 1) % CAPACITY == IDX_HEAD(q));
}

int length(Queue q){
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */
    if (isEmpty(q)){
        return 0;
    } else {
        return (((IDX_TAIL(q) - IDX_HEAD(q) + CAPACITY) % CAPACITY) + 1);
    }
}

/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, ElType val){
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */
    if (isEmpty(*q)){
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
    } else {
        if (IDX_TAIL (*q) == CAPACITY - 1){
            IDX_TAIL(*q) = 0;
        } else {
            IDX_TAIL(*q)++;
        }
    }
    TAIL(*q) = val;
}

void dequeue(Queue *q, ElType *val){
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */
    *val = HEAD(*q);
    if (IDX_HEAD(*q) == IDX_TAIL(*q)){
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    } else {
        if (IDX_HEAD(*q) == CAPACITY - 1){
            IDX_HEAD(*q) = 0;
        } else {
            IDX_HEAD(*q)++;
        }
    }
}

/* *** Display Queue *** */
void displayQueue(Queue q){
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", dan diakhiri dengan
   enter atau newline '\n' */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */
    int i;
    if (isEmpty(q)){
        printf("[]\n");
    } else {
        printf("[");
        for (i = IDX_HEAD(q); i != IDX_TAIL(q); i = (i+1) % CAPACITY){
            printf("%d,", q.buffer[i]);
        }
        printf("%d]\n", q.buffer[i]);
    }
}

/*
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
*/