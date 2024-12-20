#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"
#include "boolean.h"

Address newNode(ElType val){
/* Definisi List : */
/* List kosong : FIRST(l) = NULL */
/* Setiap elemen dengan Address p dapat diacu INFO(p), NEXT(p) */
/* Elemen terakhir list: jika addressnya Last, maka NEXT(Last)=NULL */
    Address p = (Address) malloc (sizeof(Node));
    if (p != NULL){
        INFO(p) = val;
        NEXT(p) = NULL;
    }
    return p;
}

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l){
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
    FIRST(*l) = NULL;
}

/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l){
/* Mengirim true jika list kosong */
    return (FIRST(l) == NULL);
}

/****************** GETTER SETTER ******************/
ElType getElmt(List l, int idx){
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */
    Address p;
    int i;
    p = FIRST(l);
    i = 0;
    while (i < idx){
        p = NEXT(p);
        i++;
    }
    return INFO(p);
}

void setElmt(List *l, int idx, ElType val){
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */
    Address p;
    int i;
    p = FIRST(*l);
    i = 0;
    while (i < idx){
        p = NEXT(p);
        i++;
    }
    INFO(p) = val;
}

int indexOf(List l, ElType val){
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */
    Address p;
    int i;
    boolean found;
    p = FIRST(l);
    i = 0;
    found = false;
    while (p != NULL && !found){
        if (INFO(p) == val){
            found = true;
        } else {
            p = NEXT(p);
            i++;
        }
    }
    if (found){
        return i;
    } else {
        return IDX_UNDEF;
    }
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val){
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */
    Address p;
    p = newNode(val);
    if (p != NULL){
        NEXT(p) = FIRST(*l);
        FIRST(*l) = p;
    }
}

void insertLast(List *l, ElType val){
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    Address p, last;
    if (isEmpty(*l)){
        insertFirst(l, val);
    } else {
        p = newNode(val);
        if (p !=  NULL){
            last = FIRST(*l);
            while (NEXT(last) != NULL){
                last = NEXT(last);
            }
            NEXT(last) = p;
        }
    }
}

void insertAt(List *l, ElType val, int idx){
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    Address p, loc;
    int i;
    if (idx == 0){
        insertFirst(l, val);
    } else {
        p = newNode(val);
        if (p != NULL){
            i = 0;
            loc = FIRST(*l);
            while (i < idx - 1){
                loc = NEXT(loc);
                i++;
            }
            NEXT(p) = NEXT(loc);
            NEXT(loc) = p;
        }
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val){
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
    Address p;
    p = FIRST(*l);
    *val = INFO(p);
    FIRST(*l) = NEXT(p);
    free(p);
}
void deleteLast(List *l, ElType *val){
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */
    Address p, loc;
    p = FIRST(*l);
    loc = NULL;
    while (NEXT(p) != NULL){
        loc = p;
        p = NEXT(p);
    }
    if (loc == NULL){ // only 1 el
        FIRST(*l) = NULL; 
    } else {
        NEXT(loc) = NULL;
    }
    *val = INFO(p);
    free(p);
}

void deleteAt(List *l, int idx, ElType *val){
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */
    Address p, loc;
    int i;
    if (idx == 0){
        deleteFirst(l, val);
    } else {
        i = 0;
        loc = FIRST(*l);
        while (i < idx - 1){
            loc = NEXT(loc);
            i++;
        }
        p = NEXT(loc);
        *val = INFO(p);
        NEXT(loc) = NEXT(p);
        free(p);
    }
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l){
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
    Address p;
    if (isEmpty(l)){
        printf("[]");
    } else {
        p = FIRST(l);
        printf("[");
        while (p != NULL){
            printf("%d", INFO(p));
            p = NEXT(p);
            if (p != NULL){
                printf(",");
            }
        }
        printf("]");
    }
}

int length(List l){
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
    Address p;
    int count;
    p = FIRST(l);
    count = 0;
    while (p != NULL){
        p = NEXT(p);
        count++;
    }
    return count;
}

/****************** PROSES TERHADAP LIST ******************/
List concat(List l1, List l2){
/* I.S. l1 dan l2 sembarang */
/* F.S. l1 dan l2 kosong, l3 adalah hasil konkatenasi l1 & l2 */
/* Konkatenasi dua buah list : l1 dan l2    */
/* menghasilkan l3 yang baru (dengan elemen list l1 dan l2 secara beurutan). */
/* Tidak ada alokasi/dealokasi pada prosedur ini */
    List l3;
    Address p;
    CreateList(&l3);
    p = FIRST(l1);
    while (p != NULL){
        insertLast(&l3, INFO(p));
        p = NEXT(p);
    }
    p = FIRST(l2);
    while (p != NULL){
        insertLast(&l3, INFO(p));
        p = NEXT(p);
    }
    CreateList(&l1);    
    CreateList(&l2);
    return l3;
}

/*
#include <stdio.h>
#include "listlinier.h"
#include "boolean.h"

int main(){
    List l1, l2, l3;
    int i, idx, n, val;
    CreateList(&l1);
    CreateList(&l2);
    CreateList(&l3);
    
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        scanf("%d", &val);
        insertLast(&l1, val);
    }
    if (isEmpty(l1)){
        printf("Empty list\n");
    }
    displayList(l1);
    printf("%d\n", length(l1));

    scanf("%d", &n);
    for (i = 0; i < n; i++){
        scanf("%d", &val);
        insertLast(&l2, val);
    }
    if (isEmpty(l2)){
        printf("Empty list\n");
    }
    displayList(l2);
    printf("%d\n", length(l2));

    printf("Index to get: ");
    scanf("%d", &idx);
    printf("%d\n", getElmt(l1, idx));

    printf("Index to change: ");
    scanf("%d", &idx);
    printf("New value: ");
    scanf("%d", &val);
    setElmt(&l1, idx, val);
    displayList(l1);

    printf("Value to search: ");
    scanf("%d", &val);  
    printf("%d\n", indexOf(l1, val));

    printf("Value to insert: ");
    scanf("%d", &val);
    insertFirst(&l1, val);
    displayList(l1);

    insertAt(&l1, val, idx);
    displayList(l1);

    insertLast(&l1, val);
    displayList(l1);

    deleteFirst(&l1, &val);
    displayList(l1);

    deleteAt(&l1, idx, &val);
    displayList(l1);

    deleteLast(&l1, &val);
    displayList(l1);

    l3 = concat(l1, l2);
    displayList(l3);

    return 0;
}
*/