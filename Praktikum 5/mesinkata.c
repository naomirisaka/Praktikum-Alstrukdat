#include "mesinkata.h"
#include "boolean.h"
#include <stdio.h>

boolean EndWord;
Word currentWord;

void IgnoreBlanks(){
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
    while (currentChar == BLANK) {
        ADV();
    } /* currentChar != BLANK */
}

void STARTWORD(){
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
   START();
   IgnoreBlanks();
   if (currentChar == MARK) {
      EndWord = true;
   } else /* currentChar != MARK */ {
      EndWord = false;
      CopyWord();
   }
}

void ADVWORD(){
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */
   IgnoreBlanks();
   if (currentChar == MARK){
      EndWord = true;
   } else {
      CopyWord();
      IgnoreBlanks();   
   }
}

void CopyWord(){
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
   int i = 0;
   while ((currentChar != MARK) && (currentChar != BLANK)){
      currentWord.TabWord[i] = currentChar;
      ADV();
      i++;
      currentWord.Length = i;
   }
   if (currentWord.Length > NMax){
      currentWord.Length = NMax;
   } else {
      currentWord.Length = i;
   }
}

/*
float PanjangKataRataRata() {
    int nbKata = 0;
    int lengthTotal = 0;

    startKata();
    while (!endKata){
        lengthTotal += currentKata.length;
        nbKata++;
        advKata();
    }
    if (nbKata != 0){
        return((float)lengthTotal/nbKata);
    } else {
        printf("Pita tidak mengandung kata.\n");
        return 0;
    }
}

int HitungWhile(){
    Kata kataWHILE;
    kataWHILE.buffer[0] = 'W';  //" " is for string, ' ' is for char
    kataWHILE.buffer[1] = 'H';
    kataWHILE.buffer[2] = 'I';
    kataWHILE.buffer[3] = 'L';
    kataWHILE.buffer[4] = 'E';
    kataWHILE.length = 5;
    int nWHILE = 0;
    startKata();
    while (!endKata){
        if (isKataEqual(kataWHILE, currentKata)){
            nWHILE++;
        }
        advKata();
    }
    return nWHILE;
}

boolean isKataEqual(Kata k1, Kata k2){
    if (k1.length != k2.length){
        return false;
    } else {
        for (int i = 0; i < k1.length; i++){
            if (k1.buffer[i] != k2.buffer[i]){
                return false;
            }
        }
        return true;
    }
}
*/

/*
#include <stdio.h>
#include "mesinkata.h"

int main() {
    STARTWORD();
    while (!EndWord) {
        int i;
        for (i=0; i<currentWord.Length; i++) {
            printf("%c",currentWord.TabWord[i]);
        }
        printf("\n");
        ADVWORD();
    }
    float length = PanjangKataRataRata();
    printf("%.2f\n", length);

    int count = HitungWhile();
    printf("%d\n", count);
    
    return 0;
}
*/