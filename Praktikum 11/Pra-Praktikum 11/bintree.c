#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "bintree.h"

/* Definisi PohonBiner */
BinTree NewTree (ElType root, BinTree left_tree, BinTree right_tree){
/* Menghasilkan sebuah pohon biner dari root, left_tree, dan right_tree, jika alokasi berhasil 
   Menghasilkan pohon kosong (NULL) jika alokasi gagal */
   Address p = newTreeNode(root);
   if (p != NULL){
      LEFT(p) = left_tree;
      RIGHT(p) = right_tree;
   }
   return p;
}

void CreateTree (ElType root, BinTree left_tree, BinTree right_tree, BinTree *p){
/* I.S. Sembarang
   F.S. Menghasilkan sebuah pohon p
   Menghasilkan sebuah pohon biner p dari akar, l, dan r, jika alokasi 
   berhasil 
   Menghasilkan pohon p yang kosong (NULL) jika alokasi gagal */
   *p = newTreeNode(root);
   if (*p != NULL){
      LEFT(*p) = left_tree;
      RIGHT(*p) = right_tree;
   }
}

Address newTreeNode(ElType val){
/* Alokasi sebuah address p, bernilai tidak NULL jika berhasil */
/* Mengirimkan address hasil alokasi sebuah elemen bernilai val
   Jika alokasi berhasil, maka address tidak NULL, dan misalnya 
   menghasilkan p, maka p↑.info=val, p↑.left=NULL, p↑.right=NULL 
   Jika alokasi gagal, mengirimkan NULL */
   Address p = (Address) malloc(sizeof(TreeNode));
   if (!isTreeEmpty(p)){
      ROOT(p) = val;
      LEFT(p) = NULL;
      RIGHT(p) = NULL;
   }
   return p;
}

void deallocTreeNode (Address p){
/* I.S. p terdefinisi 
   F.S. p dikembalikan ke sistem 
   Melakukan dealokasi/pengembalian address p */
   free(p);
}

boolean isTreeEmpty (BinTree p){
/* Mengirimkan true jika p adalah pohon biner yang kosong */
   return (p == NULL);
}

boolean isOneElmt (BinTree p){
/* Mengirimkan true jika p tidak kosong dan hanya terdiri atas 1 elemen */
   return (!isTreeEmpty(p) && isTreeEmpty(LEFT(p)) && isTreeEmpty(RIGHT(p)));
}

boolean isUnerLeft (BinTree p){
/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon unerleft: 
   hanya mempunyai subpohon kiri */
   return (!isTreeEmpty(p) && !isTreeEmpty(LEFT(p)) && isTreeEmpty(RIGHT(p)));
}

boolean isUnerRight (BinTree p){
/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon unerright: 
   hanya mempunyai subpohon kanan */
   return (!isTreeEmpty(p) && isTreeEmpty(LEFT(p)) && !isTreeEmpty(RIGHT(p)));
}

boolean isBinary (BinTree p){
/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon biner: 
  mempunyai subpohon kiri dan subpohon kanan */
   return (!isTreeEmpty(p) && !isTreeEmpty(LEFT(p)) && !isTreeEmpty(RIGHT(p)));
}

/* ****** Display Tree ***** */
void printPreorder(BinTree p){
/* I.S. p terdefinisi */
/* F.S. Semua simpul p sudah dicetak secara preorder: akar, pohon kiri, dan pohon kanan. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (A()()) adalah pohon dengan 1 elemen dengan akar A
   (A(B()())(C()())) adalah pohon dengan akar A dan subpohon kiri (B()()) dan subpohon kanan (C()()) */
   if (isTreeEmpty(p)){
      printf("()");
   } else {
      printf("(%d", ROOT(p));
      printPreorder(LEFT(p));
      printPreorder(RIGHT(p));
      printf(")");
   }
}

void printInorder(BinTree p){
/* I.S. p terdefinisi */
/* F.S. Semua simpul p sudah dicetak secara inorder: pohon kiri, akar, dan pohon kanan. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (()A()) adalah pohon dengan 1 elemen dengan akar A
   ((()B())A(()C())) adalah pohon dengan akar A dan subpohon kiri (()B()) dan subpohon kanan (()C()) */
   if (isTreeEmpty(p)){
      printf("()");
   } else {
      printf("(");
      printInorder(LEFT(p));
      printf("%d", ROOT(p));
      printInorder(RIGHT(p));
      printf(")");
   }
}

void printPostorder(BinTree p){
/* I.S. p terdefinisi */
/* F.S. Semua simpul p sudah dicetak secara postorder: pohon kiri, pohon kanan, dan akar. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (()()A) adalah pohon dengan 1 elemen dengan akar A
   ((()()B)(()()C)A) adalah pohon dengan akar A dan subpohon kiri (()()B) dan subpohon kanan (()()C) */
   if (isTreeEmpty(p)){
      printf("()");
   } else {
      printf("(");
      printPostorder(LEFT(p));
      printPostorder(RIGHT(p));
      printf("%d", ROOT(p));
      printf(")");
   }
}

void printTreeRec(BinTree p, int h, int depth){
/* I.S. p terdefinisi, h adalah jarak indentasi (spasi), depth adalah kedalaman */
/* F.S. Semua simpul p sudah ditulis dengan indentasi (spasi) secara preorder*/
   int i;
   if (!isTreeEmpty(p)){
      for (i = 0; i < h * depth; i++){
         printf(" ");
      }
      printf("%d\n", ROOT(p));
      printTreeRec(LEFT(p), h, depth+1);
      printTreeRec(RIGHT(p), h, depth+1);
   }
}

void printTree(BinTree p, int h){
/* I.S. p terdefinisi, h adalah jarak indentasi (spasi) */
/* F.S. Semua simpul p sudah ditulis dengan indentasi (spasi) */
/* Penulisan akar selalu pada baris baru (diakhiri newline) */
/* Contoh, jika h = 2: 
1) Pohon preorder: (A()()) akan ditulis sbb:
A
2) Pohon preorder: (A(B()())(C()())) akan ditulis sbb:
A
  B
  C
3) Pohon preorder: (A(B(D()())())(C()(E()()))) akan ditulis sbb:
A
  B
    D
  C
    E
Note: Anda boleh membuat fungsi tambahan untuk membuat implementasi fungsi ini jika diperlukan
*/
   printTreeRec(p, h, 0);
}

/*
#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"
#include "boolean.h"

int main(){
    BinTree T, T_left, T_right;
    int val;

    printf("Left child: ");
    scanf("%d", &val);
    T_left = NewTree(val, NULL, NULL);
    if (isTreeEmpty(T_right)){
        printf("Right child is empty\n");
    }
    printf("Right child: ");
    scanf("%d", &val);
    T_right = NewTree(val, NULL, NULL);
    if (isOneElmt(T_right)){
        printf("Right child is leaf\n");
    } 
    printf("Root: ");
    scanf("%d", &val);
    CreateTree(val, T_left, T_right, &T);
    if (isBinary(T)){
        printf("This is a binary tree\n");
    } else if (isUnerLeft(T)){
        printf("This is a left-leaning tree\n");
    } else if (isUnerRight(T)){
        printf("This is a right-leaning tree\n");
    }

    printf("Preorder: ");
    printPreorder(T);
    printf("\n");
    printf("Inorder: ");
    printInorder(T);
    printf("\n");
    printf("Postorder: "); 
    printPostorder(T);
    printf("\n");
    printf("Tree:\n");
    printTree(T, 2);

    return 0;
}
*/

/*
int hitungNode(BinTree root){
    int count = 0;
    if(isTreeEmpty(root)){
        count += 0;
    }
    else if(isOneElmt(root)){
        count += 0;
    }
    else if(isUnerLeft(root)){
        count += 1 + hitungNode(LEFT(root));
    }
    else if(isUnerRight(root)){
        count += 1 + hitungNode(RIGHT(root));
    }
    else{
        count += hitungNode(RIGHT(root)) + hitungNode(LEFT(root));
    }
    return count;
}


int calculateRoute(BinTree node, int n) {
    if (node == NULL) {
        return 0;
    }
    if (isTreeEmpty(LEFT(node)) && isTreeEmpty(RIGHT(node))) {
        // Leaf node
        if (ROOT(node) == n) {
            return ROOT(node) % 10000;
        } else {
            return 0;
        }
    }
    int leftResult = calculateRoute(LEFT(node), n - ROOT(node));
    int rightResult = calculateRoute(RIGHT(node), n - ROOT(node));

    return (leftResult + rightResult) % 10000;
}
int hitungBebek(BinTree root, int n) {
    return calculateRoute(root, n);
}


int max(int a, int b) {
    return (a > b) ? a : b;
}
int calculateMaxMoney(BinTree node, int stealCurrent) {
    if (node == NULL) {
        return 0;
    }
    if (stealCurrent) {
        return ROOT(node) + calculateMaxMoney(LEFT(node), 0) + calculateMaxMoney(RIGHT(node), 0);
    } else {
        int stealLeft = calculateMaxMoney(LEFT(node), 1) + calculateMaxMoney(RIGHT(node), 1);
        int skipLeft = calculateMaxMoney(LEFT(node), 0) + calculateMaxMoney(RIGHT(node), 0);
        return max(stealLeft, skipLeft);
    }
}
int hitungUang(BinTree root) {
    int stealRoot = calculateMaxMoney(root, 1);
    int skipRoot = calculateMaxMoney(root, 0);
    return max(stealRoot, skipRoot);
}

*/