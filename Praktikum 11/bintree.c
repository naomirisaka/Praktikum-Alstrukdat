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

boolean isEqual(BinTree p1, BinTree p2){
/* I.S. p1 dan p2 terdefinisi */
/* F.S. Mengirimkan true jika struktur dan nilai node pada p1 dan p2 identik, false jika tidak */
   if (isTreeEmpty(p1)){ 
      return (isTreeEmpty(p2));
   } else if (isOneElmt(p1)){
      return (isOneElmt(p2) && ROOT(p1) == ROOT(p2));
   } else if (isUnerLeft(p1)){
      if (isUnerLeft(p2)){
         if (ROOT(p1) == ROOT(p2)){
            return (isEqual(LEFT(p1), LEFT(p2)));
         } else {
            return false;
         }
      } else {
         return false;
      }
   } else if (isUnerRight(p1)){
      if (isUnerRight(p2)){
         if (ROOT(p1) == ROOT(p2)){
            return (isEqual(RIGHT(p1), RIGHT(p2)));
         } else {
            return false;
         }
      } else {
         return false;
      }
   } else {
      if (ROOT(p1) == ROOT(p2)){
         return (isEqual(LEFT(p1), LEFT(p2))) && (isEqual(RIGHT(p1), RIGHT(p2)));
      } else {
         return false;
      } 
   }
}

int getMaximumDepth(BinTree p){
/* I.S. p terdefinisi */
/* F.S. Mengembalikan kedalaman maksimum pohon biner p */
/* Kedalaman maksimum adalah panjang lintasan dari akar ke simpul daun terjauh */
/* Jika pohon kosong, maka kedalaman = 0 */
   if (isTreeEmpty(p)){
      return 0;
   } else if (isOneElmt(p)){
      return 1;
   } else if (isUnerLeft(p)){
      return (1 + getMaximumDepth(LEFT(p)));
   } else if (isUnerRight(p)){
      return (1 + getMaximumDepth(RIGHT(p)));
   } else {
      return (1 + getMaximumDepth(LEFT(p)) + getMaximumDepth(RIGHT(p)));
   }
}

BinTree createBinSearchTreeFromSortedArray(ElType* arr, ElType start, ElType end){
/* Mengembalikan pohon biner yang seimbang (balanced) dibangun dari array yang terurut */
/* arr terdefinisi dan tidak kosong, start dan end adalah indeks awal dan akhir array */
/* arr merupakan array berisi ElType yang terurut menaik (ascending) */
/* dipastikan semua elemen pada array unik */
/* Pilih elemen tengah dari array (indeks mid = (start + end) / 2) sebagai akar pohon. */
/* Pohon yang dihasilkan adalah Binary Search Tree(BST), di mana setiap node kiri lebih kecil dari parent node,
   dan setiap node kanan lebih besar dari parent node. */
/* Misalnya, jika array [1, 2, 3, 4, 5], pohon yang dihasilkan adalah:
    3
   / \
  1   4
   \   \
    2    5
*/
   if (start > end) { 
      return NULL; 
   } else {
      int mid = (start + end) / 2; 
      ElType root = arr[mid]; 

      BinTree left_subtree = createBinSearchTreeFromSortedArray(arr, start, mid - 1);
      BinTree right_subtree = createBinSearchTreeFromSortedArray(arr, mid + 1, end);

      BinTree t;
      CreateTree(root, left_subtree, right_subtree, &t);
      return t;
   }
}

int countNodes(BinTree p){
/* p terdefinisi, p adalah pohon biner yang mungkin kosong */
/* Mengembalikan jumlah seluruh node dalam pohon biner p */
/* Contoh:
   Misalkan pohon biner p adalah sebagai berikut:
       1
      / \
     2   3
    / \
   4   5

   Panggilan fungsi: countNodes(p)

   Output: 5
   Penjelasan: Pohon ini memiliki 5 simpul (1, 2, 3, 4, 5)
*/
   if (isTreeEmpty(p)){
      return 0;
   } else if (isOneElmt(p)){
      return 1;
   } else if (isUnerLeft(p)){
      return (1 + countNodes(LEFT(p)));
   } else if (isUnerRight(p)){
      return (1 + countNodes(RIGHT(p)));
   } else {
      return (1 + countNodes(LEFT(p)) + countNodes(RIGHT(p)));
   }
}

boolean foundNode (BinTree p, ElType target){
   if (isTreeEmpty(p)){
      return false;
   } else if (isOneElmt(p)){
      return (ROOT(p) == target);
   } else if (isUnerLeft(p)){
      if (ROOT(p) == target){
         return true;
      } else {
         return (foundNode(LEFT(p), target));
      }
   } else if (isUnerRight(p)){
      if (ROOT(p) == target){
         return true;
      } else {
         return (foundNode(RIGHT(p), target));
      }
   } else {
      if (ROOT(p) == target){
         return true;
      } else {
         return (foundNode(RIGHT(p), target)) || (foundNode(LEFT(p), target));
      }
   }
} 

void printPathToElement(BinTree p, ElType target){
/* I.S. p terdefinisi, target adalah elemen yang dicari dalam pohon biner p. Dipastikan node pada pohon biner p unik */
/* F.S. Menampilkan jalur menuju elemen target dalam pohon p dalam format "x -> y -> z" 
   jika elemen ditemukan, atau "-1" jika elemen tidak ditemukan */
/* Untuk memudahkan implementasi, dipastikan path tidak lebih panjang dari 100 elemen */
/* Contoh:
   Jika pohon p adalah:
       1
      / \
     2   3
    / \
   4   5

   Panggilan: printPathToElement(p, 5)
   Output: 1 -> 2 -> 5
*/
   if (isTreeEmpty(p)){
      printf("-1\n");
   } else if (isOneElmt(p)){
      if (ROOT(p) == target){
         printf("%d\n", ROOT(p));
      } else {
         printf("-1\n");
      }
   } else if (isUnerLeft(p)){
      if (ROOT(p) == target){
         printf("%d\n", ROOT(p));
      } else if (foundNode(LEFT(p), target)){
         printf("%d -> ", ROOT(p));
         printPathToElement(LEFT(p), target);
      } else {
         printf("-1\n");
      }
   } else if (isUnerRight(p)){
      if (ROOT(p) == target){
         printf("%d\n", ROOT(p));
      } else if (foundNode(RIGHT(p), target)){
         printf("%d -> ", ROOT(p));
         printPathToElement(RIGHT(p), target);
      } else {
         printf("-1\n");
      }
   } else {
      if (ROOT(p) == target){
         printf("%d\n", ROOT(p));
      } else if (foundNode(LEFT(p), target)){
         printf("%d -> ", ROOT(p));
         printPathToElement(LEFT(p), target);
      } else if (foundNode(RIGHT(p), target)){
         printf("%d -> ", ROOT(p));
         printPathToElement(RIGHT(p), target);
      } else {
         printf("-1\n");
      }
   }
}  