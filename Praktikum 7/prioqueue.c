#include <stdio.h>
#include "boolean.h"
#include "prioqueue.h"

/* *** Kreator *** */
void CreatePrioQueue(PrioQueue *pq){
/* I.S. sembarang */
/* F.S. Sebuah pq kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah pq kosong */
    IDX_HEAD(*pq) = IDX_UNDEF;
    IDX_TAIL(*pq) = IDX_UNDEF;
}

/* ********* Prototype ********* */
boolean isEmpty(PrioQueue pq){
/* Mengirim true jika pq kosong: lihat definisi di atas */
    return (IDX_HEAD(pq) == IDX_UNDEF && IDX_TAIL(pq) == IDX_UNDEF);
}
boolean isFull(PrioQueue pq){
/* Mengirim true jika tabel penampung elemen pq sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/
    return ((IDX_TAIL(pq) + 1) % CAPACITY == IDX_HEAD(pq));
}

int length(PrioQueue pq){
/* Mengirimkan banyaknya elemen prioqueue. Mengirimkan 0 jika pq kosong. */
    if (isEmpty(pq)){
        return 0;
    } else {
        return (((IDX_TAIL(pq) - IDX_HEAD(pq) + CAPACITY) % CAPACITY) + 1);
    }
}

/* *** Primitif Add/Delete *** */
void enqueue(PrioQueue *pq, ElType val){
/* Proses: Menambahkan val pada pq dengan aturan FIFO */
/* I.S. pq mungkin kosong, tabel penampung elemen pq TIDAK penuh */
/* F.S. val disisipkan pada posisi yang sesuai, IDX_TAIL "mundur" dalam buffer melingkar.,
        pq terurut mengecil */
    if (isEmpty(*pq)){
        IDX_HEAD(*pq) = 0;
        IDX_TAIL(*pq) = 0;
    } else {
        if (IDX_TAIL (*pq) == CAPACITY - 1){
            IDX_TAIL(*pq) = 0;
        } else {
            IDX_TAIL(*pq)++;
        }
    }
    TAIL(*pq) = val;
    int i = IDX_TAIL(*pq);
    int j;
    j = (i - 1 + CAPACITY) % CAPACITY; // dont use i == 0 then length -1, etc.

    while (i != IDX_HEAD(*pq) && (*pq).buffer[i] > (*pq).buffer[j]){
        ElType temp = (*pq).buffer[i];
        (*pq).buffer[i] = (*pq).buffer[j];
        (*pq).buffer[j] = temp;
        i = j;
        j = (i - 1 + CAPACITY) % CAPACITY; // dont use i == 0 then length -1, etc.
    }
}

void dequeue(PrioQueue *pq, ElType *val){
/* Proses: Menghapus val pada pq dengan aturan FIFO */
/* I.S. pq tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        pq mungkin kosong */
    *val = HEAD(*pq);
    if (IDX_HEAD(*pq) == IDX_TAIL(*pq)){
        IDX_HEAD(*pq) = IDX_UNDEF;
        IDX_TAIL(*pq) = IDX_UNDEF;
    } else {
        if (IDX_HEAD(*pq) == CAPACITY - 1){
            IDX_HEAD(*pq) = 0;
        } else {
            IDX_HEAD(*pq)++;
        }
    }
}
/* *** Display Queue *** */
void displayPrioQueue(PrioQueue pq){
/* Proses : Menuliskan isi PrioQueue dengan traversal, PrioQueue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. pq boleh kosong */
/* F.S. Jika pq tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 30, 20, 1 akan dicetak: [30,20,1] */
/* Jika Queue kosong : menulis [] */
    int i;
    if (isEmpty(pq)){
        printf("[]\n");
    } else {
        printf("[");
        i = IDX_HEAD(pq);
        while (i != IDX_TAIL(pq)){
            printf("%d,", pq.buffer[i]);
            i = (i+1) % CAPACITY;
        }
        printf("%d]\n", TAIL(pq));
    }
}