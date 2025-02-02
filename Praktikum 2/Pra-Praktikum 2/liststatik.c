#include "liststatik.h"
#include <stdio.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListStatik(ListStatik *l){
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan MARK */
    IdxType i;
    for (i = 0; i < CAPACITY; i++){
        ELMT(*l, i) = MARK;         // use pointer bcs ini modify
    }
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength(ListStatik l){
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */  
    int length = 0;
    IdxType i = 0;
    while (i < CAPACITY && ELMT(l, i) != MARK){
        length ++;
        i++;
    }
    return length;
}

/* *** Selektor INDEKS *** */
IdxType getFirstIdx(ListStatik l){
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
    return IDX_MIN;
}
IdxType getLastIdx(ListStatik l){
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
    return (listLength(l) - 1);
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListStatik l, IdxType i){
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
/* yaitu antara indeks yang terdefinisi utk container*/
    return (i >= 0 && i < CAPACITY);
}
boolean isIdxEff(ListStatik l, IdxType i){
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..length(l)-1 */
    return (i >= 0 && i < listLength(l));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmpty(ListStatik l){
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
    return (listLength(l) == 0);
}
/* *** Test List penuh *** */
boolean isFull(ListStatik l){
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */
    return (listLength(l) == CAPACITY);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */
void readList(ListStatik *l){
/* I.S. l sembarang */
/* F.S. List l terdefinisi */
/* Proses: membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya n */
/*    Pembacaan diulangi sampai didapat n yang benar yaitu 0 <= n <= CAPACITY */
/*    Jika n tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < n <= CAPACITY; Lakukan n kali: 
          Baca elemen mulai dari indeks 0 satu per satu diakhiri enter */
/*    Jika n = 0; hanya terbentuk List kosong */
    int n, i;
    scanf("%d", &n);
    while (n < 0 || n > CAPACITY){
        scanf("%d", &n);
    }
    CreateListStatik(l);
    for (i = 0; i < n; i++){
        scanf("%d", &ELMT(*l, i));
    }
}
void printList(ListStatik l){
/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List kosong : menulis [] */
    IdxType i;
    if (listLength(l) == 0){
        printf("[]");
    } else {
        printf("[");
        for (i = 0; i < listLength(l); i++){
            printf("%d", ELMT(l, i));
            if (i != getLastIdx(l)){
                printf(",");
            }
        }
        printf("]");
    }
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika List : Penjumlahan, pengurangan, perkalian, ... *** */
ListStatik plusMinusList(ListStatik l1, ListStatik l2, boolean plus){
/* Prekondisi : l1 dan l2 berukuran sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada 
       indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi 
       elemen l2 pada indeks yang sama */
    ListStatik l3;
    IdxType i;
    CreateListStatik(&l3); // unlike prev adt, ini harus create dulu listnya (not auto)
    if (plus) {
        for (i = 0; i < listLength(l1); i++){
            ELMT(l3, i) = ELMT(l1, i) + ELMT(l2, i);
        }
    } else {
        for (i = 0; i < listLength(l1); i++){
            ELMT(l3, i) = ELMT(l1, i) - ELMT(l2, i);
        }        
    }
    return l3;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan List: *** */
boolean isListEqual(ListStatik l1, ListStatik l2){
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika ukuran l1 = l2 dan semua 
   elemennya sama */
    IdxType i;
    boolean equal;
    if (listLength(l1) != listLength(l2)){
        return false;
    } else {
        equal = true;
        i = 0;
        while (i < listLength(l1) && equal){
            if (ELMT(l1, i) != ELMT(l2,i)){
                equal = false;
            }
            i++;
        }
        return equal;
    }
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int indexOf(ListStatik l, ElType val){
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */
    int i;      // should only be int i if it needs to be returned in the func, otherwise use IdxType i
    for (i = 0; i < listLength(l); i++){
        if (ELMT(l,i) == val){
            return i;
        }
    }
    return IDX_UNDEF;
}

/* ********** NILAI EKSTREM ********** */
void extremeValues(ListStatik l, ElType *max, ElType *min){
/* I.S. List l tidak kosong */
/* F.S. Max berisi nilai terbesar dalam l;
        Min berisi nilai terkecil dalam l */
    IdxType i;
    *min = ELMT(l,0);
    *max = ELMT(l,0);
    for (i = 1; i < listLength(l); i++){
        if (ELMT(l,i) < *min){
            *min = ELMT(l,i);
        }
        if (ELMT(l,i) > *max){
            *max = ELMT(l,i);
        }
    }
}

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void insertFirst(ListStatik *l, ElType val){
/* Proses: Menambahkan val sebagai elemen pertama List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen pertama l yang baru */
    IdxType i;
    for (i = listLength(*l); i > 0; i--){
        ELMT(*l,i) = ELMT(*l,i-1);
    }
    ELMT(*l,0) = val;
}
/* *** Menambahkan elemen pada index tertentu *** */
void insertAt(ListStatik *l, ElType val, IdxType idx){
/* Proses: Menambahkan val sebagai elemen pada index idx List */
/* I.S. List l tidak kosong dan tidak penuh, idx merupakan index yang valid di l */
/* F.S. val adalah elemen yang disisipkan pada index idx l */
    IdxType i;
    for (i = listLength(*l); i > idx; i--){
        ELMT(*l,i) = ELMT(*l,i-1);
    }
    ELMT(*l,idx) = val;    
}
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListStatik *l, ElType val){
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
    ELMT(*l,listLength(*l)) = val;
}

/* ********** MENGHAPUS ELEMEN ********** */
/* *** Menghapus elemen pertama *** */
void deleteFirst(ListStatik *l, ElType *val){
/* Proses : Menghapus elemen pertama List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen pertama l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
    IdxType i;
    *val = ELMT(*l, 0);
    for (i = 0; i < getLastIdx(*l); i++){
        ELMT(*l,i) = ELMT(*l,i+1);
    }
    ELMT(*l,getLastIdx(*l)) = MARK;
}
/* *** Menghapus elemen pada index tertentu *** */
void deleteAt(ListStatik *l, ElType *val, IdxType idx){
/* Proses : Menghapus elemen pada index idx List */
/* I.S. List tidak kosong, idx adalah index yang valid di l */
/* F.S. val adalah nilai elemen pada index idx l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
    IdxType i;
    *val = ELMT(*l, idx);
    for (i = idx; i < getLastIdx(*l); i++){
        ELMT(*l,i) = ELMT(*l,i+1);
    }
    ELMT(*l,getLastIdx(*l)) = MARK;
}
/* *** Menghapus elemen terakhir *** */
void deleteLast(ListStatik *l, ElType *val){
/* Proses : Menghapus elemen terakhir List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
    *val = ELMT(*l,getLastIdx(*l));
    ELMT(*l,getLastIdx(*l)) = MARK;
}

/* ********** SORTING ********** */
void sortList(ListStatik *l, boolean asc){
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */
    IdxType pass, i_max, i_min, i;
    ElType temp;
    if (listLength(*l) > 1){
        if (asc){   // using selection sort
            for (pass = 0; pass < listLength(*l); pass++){
                i_min = pass;
                for (i = pass+1; i < listLength(*l); i++){
                    if (ELMT(*l,i_min) > ELMT(*l,i)){
                        i_min = i;
                    }
                }
                temp = ELMT(*l,i_min);
                ELMT(*l,i_min) = ELMT(*l, pass);
                ELMT(*l,pass) = temp;
            }
        } else { // descending
            for (pass = 0; pass < listLength(*l); pass++){
                i_max = pass;
                for (i = pass+1; i < listLength(*l); i++){
                    if (ELMT(*l,i_max) < ELMT(*l,i)){
                        i_max = i;
                    }
                }
                temp = ELMT(*l,i_max);
                ELMT(*l,i_max) = ELMT(*l, pass);
                ELMT(*l,pass) = temp;
            }
        }
    }
}


/*
#include "liststatik.h"
#include <stdio.h>

int main(){
    ListStatik l1, l2, l_op;
    IdxType n;
    ElType val;
    int val_loc, min, max;
    boolean plus, asc;
    readList(&l1);
    printList(l1);
    printf("\nPanjang list: %d\n", listLength(l1));
    if (isEmpty(l1)){
        printf("List kosong\n");
    } else if (isFull(l1)) {
        printf("List penuh\n");
    } else {
        printf("List tidak kosong maupun penuh\n");
    }
    printf("Index pertama list: %d\n", getFirstIdx(l1));
    printf("Index terakhir list: %d\n", getLastIdx(l1));
    printf("Index untuk dicek pada list: ");
    scanf("%d", &n); // scanf auto enter afterwards
    if (isIdxValid(l1,n)){
        printf("Index dalam kapasitas list\n");
    } else {
        printf("Index tidak valid\n");
    }
    if (isIdxEff(l1,n)){
        printf("Index efektif\n");
    } else {
        printf("Index tidak efektif\n");
    }
    readList(&l2); // make it the same size as l1
    printList(l2);
    plus = true;
    l_op = plusMinusList(l1,l2,plus);
    printf("\nL1 + L2 = ");
    printList(l_op);
    plus = false;
    l_op = plusMinusList(l1,l2,plus);
    printf("\nL1 - L2 = ");
    printList(l_op);
    printf("\n");
    if (isListEqual(l1,l2)){
        printf("List equal\n");
    } else {
        printf("List tidak equal\n");
    }
    printf("Value yang ingin dicari/ditambah: ");
    scanf("%d", &val);
    printf("Index ke: ");
    scanf("%d", &n);
    val_loc = indexOf(l1, val);
    printf("Lokasi value: %d\n", val_loc);
    extremeValues(l1,&max,&min);
    printf("Min: %d\n", min);
    printf("Max: %d\n", max);
    insertFirst(&l1, val);
    printList(l1);
    printf("\n");
    insertAt(&l1, val, n);
    printList(l1);
    printf("\n");
    insertLast(&l1, val);
    printList(l1);
    printf("\n");
    deleteFirst(&l1, &val);
    printList(l1);
    printf("\n");
    deleteAt(&l1, &val, n);
    printList(l1);
    printf("\n");
    deleteLast(&l1, &val);
    printList(l1);
    printf("\n");
    asc = true;
    sortList(&l1, asc);
    printList(l1);
    printf("\n");
    asc = false;
    sortList(&l2, asc);
    printList(l2);
    printf("\n");
    return 0;
}
*/