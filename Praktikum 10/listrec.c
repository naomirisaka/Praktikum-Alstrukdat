#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "listrec.h"

/* Manajemen Memori */
Address newNode(ElType x){
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak NIL, dan misalnya
   menghasilkan p, maka INFO(p)=x, NEXT(p)=NIL */
/* Jika alokasi gagal, mengirimkan NIL */
    Address p = (Address) malloc(sizeof(Node));
    if (p != NIL){
        INFO(p) = x;
        NEXT(p) = NIL;
    }
    return p;
} 

/* Pemeriksaan Kondisi List */
boolean isEmpty(List l){
/* Mengirimkan true jika l kosong dan false jika l tidak kosong */
    return (l == NIL);
}
boolean isOneElmt(List l){
/* Mengirimkan true jika l berisi 1 elemen dan false jika > 1 elemen atau kosong */
    return (length(l) == 1);
}

/* Primitif-Primitif Pemrosesan List */
ElType head(List l){
/* Mengirimkan elemen pertama sebuah list l yang tidak kosong */
    return INFO(l);
}
List tail(List l){
/* Mengirimkan list l tanpa elemen pertamanya, mungkin mengirimkan list kosong */
    return NEXT(l);
}
List konso(List l, ElType e){
/* Mengirimkan list l dengan tambahan e sebagai elemen pertamanya. e dialokasi terlebih dahulu. 
   Jika alokasi gagal, mengirimkan l */
    Address p = newNode(e);
    if (p != NIL){
        NEXT(p) = l;
        return p;
    } else {
        return l;
    }
}
List konsb(List l, ElType e){
/* Mengirimkan list l dengan tambahan e sebagai elemen terakhirnya */
/* e harus dialokasi terlebih dahulu */
/* Jika alokasi e gagal, mengirimkan l */ 
    Address p = newNode(e);
    if (p != NIL){
        if (isEmpty(l)){
            return p;
        } else {
            NEXT(l) = konsb(tail(l), e);
            return l;
        }
    } else {
        return l;
    }
}
List copy(List l){
/* Mengirimkan salinan list Ll (menjadi list baru) */
/* Jika ada alokasi gagal, mengirimkan l */ 
    if (isEmpty(l)){
        return NIL;
    } else {
        return konso(copy(tail(l)), head(l));
    }
}
List concat(List l1, List l2){
/* Mengirimkan salinan hasil konkatenasi list l1 dan l2 (menjadi list baru) */
/* Jika ada alokasi gagal, menghasilkan NIL */
    if (isEmpty(l1)){
        return copy(l2);
    } else if (isEmpty(l2)){
        return copy(l1);
    } else {
        return konso(concat(tail(l1), l2), head(l1));
    }
}

/* Fungsi dan Prosedur Lain */
int length(List l){
/* Mengirimkan banyaknya elemen list l, mengembalikan 0 jika l kosong */
    if (isEmpty(l)){
        return 0;
    } else {
        return (1 + length(tail(l)));
    }
}
boolean isMember(List l, ElType x){
/* Mengirimkan true jika x adalah anggota list l dan false jika tidak */
    if (isEmpty(l)){
        return false;
    } else {
        if (head(l) == x){
            return true;
        } else {
            return isMember(tail(l), x);
        }
    }
}
void displayList(List l){
/* I.S. List l mungkin kosong */
/* F.S. Jika list tidak kosong, nilai list dicetak ke bawah */
/*      Dipisahkan dengan newline (\n) dan diakhiri dengan newline */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak:
  1
  20
  30
 */
/* Jika list kosong, tidak menuliskan apa-apa */
    if (!isEmpty(l)){
        printf("%d\n", head(l));
        displayList(tail(l));
    }
}

/*** Tambahan primitif pemrosesan list ***/
List insertAt(List l, ElType e, int idx){
/* Fungsi untuk menambahkan e sebagai elemen pada posisi/index idx sebuah list l */
    if (idx == 0){
        return konso(l, e);
    }
    else{
        return konso(insertAt(tail(l), e, idx - 1), head(l));
    }
}

List deleteFirst(List l){
/* Fungsi untuk menghapus elemen pertama sebuah list l */
    Address p = l;
    l = tail(l);
    free(p);
    return l;
}

List deleteAt(List l, int idx){
/* Fungsi untuk menghapus elemen pada posisi/index idx sebuah list l */
    if (idx == 0){
        return (deleteFirst(l));
    } else {
        return (konso(deleteAt(tail(l), idx - 1), head(l)));
    }
}

List deleteLast(List l){
/* Fungsi untuk menghapus elemen terakhir sebuah list l */
    return (deleteAt(l, length(l) - 1));
}

/*** Operasi-Operasi Lain ***/
List reverseList (List l){
/* Mengirimkan list baru, list l yang dibalik dengan menyalin semua elemen list.
Semua elemen list baru harus dialokasi */
/* Jika alokasi gagal, hasilnya list kosong */
    if (isEmpty(l) || isOneElmt(l)){ 
        return l;
    } else {
       return konsb(reverseList(tail(l)), head(l));
    }
}

void splitOddEven (List l, List *l1, List *l2){
/* I.S. l mungkin kosong */
/* F.S. Berdasarkan l, dibentuk dua buah list l1 dan l2 */ 
/* l1 berisi semua elemen l yang genap, sedangkan l2 berisi
semua elemen l yang ganjil; semua dengan urutan yang sama seperti di l */
/* l tidak berubah: Semua elemen l1 dan l2 harus dialokasi */
/* Jika l kosong, maka l1 dan l2 kosong */
    if (isEmpty(l)){
        *l1 = NIL; 
        *l2 = NIL;
    } else {
        splitOddEven(tail(l), l1, l2);
        if (head(l) % 2 == 0){
            *l1 = konso(*l1, head(l));
        } else {
            *l2 = konso(*l2, head(l));
        }
    }
} 

void splitOnX (List l, int x, List *l1, List *l2){
/* I.S. l dan x terdefinisi, l1 dan l2 sembarang. */
/* F.S. l1 berisi semua elemen l yang sebelum indeks ke-x 
      l2 berisi semua elemen l setelah indeks ke-x (termasuk indeks ke-x) */
    if (isEmpty(l)) {
        *l1 = NIL;
        *l2 = NIL;
    } else if (x <= 0) {
        splitOnX(tail(l) , x , l1 , l2);
        *l2 = konso(*l2 , head(l));
    } else {
        splitOnX(tail(l), x - 1, l1, l2);
        *l1 = konso(*l1, head(l));
    }
}

ElType getMiddle(List l){
/* I.S. l terdefinisi, bukan list kosong */
/* F.S. Mengembalikan elemen tengah dari List l */
/* Jika jumlah elemen dalam List l ganjil, elemen tengah adalah elemen yang berada di posisi tengah.
   Jika jumlah elemen dalam List l genap, elemen tengah adalah elemen di posisi tengah kedua. */
/* Contoh:
   l = [1, 2, 3, 4, 5]
   elemen tengah = 3

   l = [1, 6, 3, 10]
   elemen tengah = 3 (6 dan 3 berada di tengah, dikembalikan elemen tengah kedua, yaitu 3) */
    int len, i, mid;
    Address p = l;
    len = length(l);  
    i = 0;
    mid = len / 2;
    while (i < mid){
        p = tail(p);
        i++;
    }
    return (head(p));
}

/*
#include <stdio.h>
#include "boolean.h"
#include "listrec.h"

int main(){
    List l1 = NIL, l2 = NIL, l1_rev = NIL; // init listrec
    int n, i, val, idx;

    printf("List 1\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        scanf("%d", &val);
        l1 = konsb(l1, val);
    }
    displayList(l1);
    if (isEmpty(l1)){
        printf("Empty list\n");
    } else if (isOneElmt(l1)){
        printf("List has 1 element\n");
    }
    printf("List length: %d\n", length(l1));

    printf("Middle of list 1: %d\n", getMiddle(l1));

    l1_rev = reverseList(l1);
    displayList(l1_rev);
    
    printf("Value to insert in front: ");
    scanf("%d", &val);
    displayList(konso(l1, val)); // l1 stays the same
    
    printf("Index to insert/delete at: ");
    scanf("%d", &idx);
    displayList(insertAt(l1, val, idx));

    printf("/n");
    displayList(deleteFirst(l1));

    printf("/n");
    displayList(deleteLast(l1));

    printf("/n");
    displayList(deleteAt(l1, idx));

    printf("Value to check: ");
    scanf("%d", &val);
    if (isMember(l1, val)){
        printf("Value found in list\n");
    } else {
        printf("Value not found in list\n");
    }

    List l3 = NIL, l4 = NIL;
    splitOddEven(l1, &l3, &l4);
    printf("Odd list:\n");
    displayList(l3);
    printf("Even list:\n");
    displayList(l4);

    l3 = NIL, l4 = NIL;
    printf("Index to split on: ");
    scanf("%d", &idx);
    splitOnX(l1, idx, &l3, &l4);
    printf("List before idx:\n");
    displayList(l3);
    printf("List after idx:\n");
    displayList(l4);

    printf("List 2\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        scanf("%d", &val);
        l2 = konsb(l2, val);
    }
    displayList(l2);

    printf("Concatenated list:\n");
    displayList(concat(l1, l2));

    return 0;
}
*/