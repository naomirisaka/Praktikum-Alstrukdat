#include <stdio.h>
#include "boolean.h"
#include "stack.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmpty(Stack *S){
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */
    Top(*S) = Nil;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmpty(Stack S){
/* Mengirim true jika Stack kosong: lihat definisi di atas */
    return (Top(S) == Nil);
}
boolean IsFull(Stack S){
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
    return (Top(S) == MaxEl-1);
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stack * S, infotype X){
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
    if (Top(*S) == Nil){
        Top(*S) = 0;
    } else {
        Top(*S)++;
    }
    InfoTop(*S) = X;
}

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack * S, infotype* X){
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
    *X = InfoTop(*S);
    if (Top(*S) == 0){
        Top(*S) = Nil;
    } else {
        Top(*S)--;
    }
}

/*
#include <stdio.h>
#include "boolean.h"
#include "stack.h"

int main(){
    Stack s;
    int i, n, x;
    CreateEmpty(&s);
    printf("Amount of var: ");
    scanf("%d", &n);
    i = 0;
    while (i < n){
        scanf("%d", &x);
        Push(&s, x);
        i++;
    }
    if (IsFull(s)){
        printf("Full stack\n");
    }
    if (!IsEmpty(s)){
        Pop(&s, &x);
        printf("Top: %d\n", x);
    }
    return 0;
}
*/