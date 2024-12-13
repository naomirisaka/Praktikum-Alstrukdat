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
    return (!isEmpty(l) && NEXT(l) == NIL);
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
    if (isEmpty(l)){
        return newNode(e);
    } else {
        NEXT(l) = konsb(tail(l), e);
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

/*
#include <stdio.h>
#include "boolean.h"
#include "listrec.h"

int main(){
    List l1 = NULL, l2 = NULL; // init listrec
    int n, i, val;

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
    
    printf("Value to insert in front: ");
    scanf("%d", &val);
    displayList(konso(l1, val)); // l1 stays the same

    printf("Value to check: ");
    scanf("%d", &val);
    if (isMember(l1, val)){
        printf("Value found in list\n");
    } else {
        printf("Value not found in list\n");
    }

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

/*
List insertAt(List l, ElType e, int idx){
    if (idx == 0){
        return konso(l, e);
    }
    else{
        return konso(insertAt(tail(l), e, idx-1), head(l));
    }

}

List deleteFirst(List l){
    return tail(l);
}

List deleteAt(List l, int idx){
    if (idx == 0){
        return tail(l);
    }
    else{
        return konso(deleteAt(tail(l), idx-1), head(l));
    }
}

List deleteLast(List l){
    if (isEmpty(tail(l))){
        return NIL;
    }
    else{
        return konso(deleteLast(tail(l)), head(l));
    }
}

List inverseList (List l){
    if (isEmpty(l)){
        return l;
    }
    else if(isOneElmt(l)){
        return l;
    }
    else{   
        return konsb(inverseList(tail(l)),head(l));
    }
}

void splitPosNeg (List l, List *l1, List *l2){
    if (isEmpty(l)){
        *l1 = NULL;
        *l2 = NULL;
    }
    else{
        if (head(l) >= 0){
            splitPosNeg(tail(l), l1, l2);
            *l1 = konso(*l1,head(l));
        }
        else{
            splitPosNeg(tail(l), l1, l2);
            *l2 = konso(*l2,head(l));
        }
    }
}

void splitOnX (List l, ElType x, List *l1, List *l2){
    if (isEmpty(l)){
        *l1 = NULL;
        *l2 = NULL;
    }
    else{
        splitOnX(tail(l),x,l1,l2);
        if (head(l) < x){
            *l1 = konso(*l1,head(l));
        }
        else{
            *l2 = konso(*l2, head(l));
        }
    }
}

List removeDuplicate(List l, List unique){
    if (isEmpty(l)){
        return unique;
    }
    else{
        if (!isMember(unique, head(l))){
            unique = konso(unique, head(l));
        }
        return removeDuplicate(tail(l), unique);
    }
}
*/