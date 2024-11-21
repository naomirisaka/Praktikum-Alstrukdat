#include "listdin.h"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDin(ListDin *l, int capacity){
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
   BUFFER(*l) = (int*) malloc(capacity*sizeof(int));
   CAPACITY(*l) = capacity;
   NEFF(*l) = 0;
}

void dealocateList(ListDin *l){
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */
   free(BUFFER(*l));
   CAPACITY(*l) = 0;
   NEFF(*l) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength(ListDin l){
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */
   return (NEFF(l));
}

/* *** Selektor INDEKS *** */
IdxType getFirstIdx(ListDin l){
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
   return (IDX_MIN);
}
IdxType getLastIdx(ListDin l){
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
   return (NEFF(l)-1);
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListDin l, IdxType i){
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
   return (i >= 0 && i < CAPACITY(l));
}
boolean isIdxEff(ListDin l, IdxType i){
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */
   return (i >= 0 && i < listLength(l));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmpty(ListDin l){
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
   return (listLength(l) == 0);
}
/* *** Test list penuh *** */
boolean isFull(ListDin l){
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
   return (listLength(l) == CAPACITY(l));
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void readList(ListDin *l){
/* I.S. l sembarang dan sudah dialokasikan sebelumnya */
/* F.S. List l terdefinisi */
/* Proses : membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITY(l) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= CAPACITY(l); Lakukan N kali: Baca elemen mulai dari indeks
      0 satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk l kosong */
   int N, i;
   scanf("%d", &N);
   while (N < 0 || N > CAPACITY(*l)){
      scanf("%d", &N);
   }
   NEFF(*l) = N;
   for (i = 0; i < N; i++){
      scanf("%d", &ELMT(*l, i));
   }
}
void printList(ListDin l){
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
   int i;
   printf("[");
   for (i = 0; i < listLength(l); i++){
      printf("%d", ELMT(l, i));
      if (i != getLastIdx(l)){
         printf(",");
      }
   }
   printf("]");
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika list : Penjumlahan, pengurangan, perkalian, ... *** */
ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus){
/* Prekondisi : l1 dan l2 memiliki Neff sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama */
   ListDin l3;
   int i;
   CreateListDin(&l3, CAPACITY(l1));
   NEFF(l3) = NEFF(l1);
   if (plus){
      for (i = 0; i < listLength(l1); i++){
         ELMT(l3, i) = ELMT(l1,i) + ELMT (l2,i);
      }
   } else {
      for (i = 0; i < listLength(l1); i++){
         ELMT(l3, i) = ELMT(l1,i) - ELMT (l2,i);
      }
   }
   return l3;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
boolean isListEqual(ListDin l1, ListDin l2){
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */
   int i;
   if (NEFF(l1) != NEFF(l2)){
      return false;
   } else {
      for (i = 0; i < listLength(l1); i++){
         if (ELMT(l1, i) != ELMT(l2, i)){
            return false;
         }
      }
      return true;
   }
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
IdxType indexOf(ListDin l, ElType val){
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan IDX_UNDEF */
/* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
/* Skema Searching yang digunakan bebas */
   int i;
   if(NEFF(l) == 0){
      return IDX_UNDEF;
   } else {
      for (i = 0; i < listLength(l); i++){
         if (ELMT(l,i) == val){
            return i;
         }
      }
      return IDX_UNDEF;
   }
   
}

/* ********** NILAI EKSTREM ********** */
void extremeValues(ListDin l, ElType *max, ElType *min){
/* I.S. List l tidak kosong */
/* F.S. max berisi nilai maksimum l;
        min berisi nilai minimum l */
   int i;
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

/* ********** OPERASI LAIN ********** */
void copyList(ListDin lIn, ListDin *lOut){
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */ 
   int i;
   dealocateList(lOut);
   CreateListDin(lOut, CAPACITY(lIn));
   NEFF(*lOut) = NEFF(lIn);
   for (i = 0; i < listLength(*lOut); i++){
      ELMT(*lOut,i) = ELMT(lIn, i);
   }
}
ElType sumList(ListDin l){
/* Menghasilkan hasil penjumlahan semua elemen l */
/* Jika l kosong menghasilkan 0 */
   int i, count;
   count = 0;
   for (i = 0; i < listLength(l); i++){
      count += ELMT(l,i);
   }
   return count;
}
int countVal(ListDin l, ElType val){
/* Menghasilkan berapa banyak kemunculan val di l */
/* Jika l kosong menghasilkan 0 */
   int i, amt;
   amt = 0;
   for (i = 0; i < listLength(l); i++){
      if (ELMT(l,i) == val){
         amt++;
      }
   }
   return amt;
}

/* ********** SORTING ********** */
void sort(ListDin *l, boolean asc){
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */
   int pass, i_max, i_min, i;
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

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListDin *l, ElType val){
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
   ELMT(*l, NEFF(*l)) = val;
   NEFF(*l)++;
}
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast(ListDin *l, ElType *val){
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */
   *val = ELMT(*l, getLastIdx(*l));
   NEFF(*l)--;
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandList(ListDin *l, int num){
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */
   ListDin temp;
   int i;
   CreateListDin(&temp, CAPACITY(*l));
   NEFF(temp) = NEFF(*l);
   copyList(*l, &temp);
   dealocateList(l);
   CreateListDin(l, CAPACITY(temp)+num);
   NEFF(*l) = NEFF(temp);
   for (i = 0; i < listLength(*l); i++){
      ELMT(*l,i) = ELMT(temp, i);
   }
   dealocateList(&temp);
}

void shrinkList(ListDin *l, int num){
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */
   ListDin temp;
   int i;
   CreateListDin(&temp, CAPACITY(*l));
   NEFF(temp) = NEFF(*l);
   copyList(*l, &temp);
   dealocateList(l);
   CreateListDin(l, CAPACITY(temp)-num);
   NEFF(*l) = NEFF(temp);
   for (i = 0; i < listLength(*l); i++){
      ELMT(*l,i) = ELMT(temp, i);
   }
   dealocateList(&temp);
}

void compressList(ListDin *l){
/* Proses : Mengubah capacity sehingga nEff = capacity */
/* I.S. List tidak kosong */
/* F.S. Ukuran nEff = capacity */
   shrinkList(l, CAPACITY(*l)-NEFF(*l));
}

/*
void countSort(ListDin *l);
//Mengurutkan dengan skema sorting counting sort
void countSort(ListDin *l){
   ListDin l_count;
   int min, max, range, i, j;
   extremeValues(*l, &max, &min);
   range = max - min + 1;
   CreateListDin(&l_count, range);
   NEFF(l_count) = range;
   for (i = 0; i < range; i++) {
      ELMT(l_count, i) = 0;
   }
   for (j = 0; j < listLength(*l); j++) {
      int index = ELMT(*l, j) - min;  
      ELMT(l_count, index) += 1;
   }
   int sortedIdx = 0;
   for (i = 0; i < range; i++) {
      while (ELMT(l_count, i) > 0) {
         ELMT(*l, sortedIdx++) = i + min;  
         ELMT(l_count, i)--; 
      }
   }
   dealocateList(&l_count);
}
*/

/*
#include "listdin.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    ListDin l1, l2, l_op;
    int n;
    ElType val, keep_val;
    int val_loc, min, max, sum_val;
    boolean plus, asc;
    CreateListDin(&l1, 10);
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
    CreateListDin(&l2, 10);
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
    printf("Jumlah kemunculan value: %d\n", countVal(l1, val));
    extremeValues(l1,&max,&min);
    printf("Min: %d\n", min);
    printf("Max: %d\n", max);
    sum_val = sumList(l1);
    printf("Total values: %d\n", sum_val);
    compressList(&l1);
    if (isFull(l1)){
        expandList(&l1,10);
    }
    insertLast(&l1, val);
    printList(l1);
    if (NEFF(l2) < (CAPACITY(l2)/2)){
        shrinkList(&l2, 5);
    }
    deleteLast(&l2, &keep_val);
    printList(l2);
    asc = true;
    sort(&l1, asc);
    printList(l1);
    printf("\n");
    asc = false;
    sort(&l2, asc);
    printList(l2);
    printf("\n");
    return 0;
}
*/

// wrong tc 27