#include <stdio.h>
#include "mesinkata.h"

int main(){
    STARTWORD();
    int i, j, n;
    i = 1;
    char word [100];
    while (!EndWord){
        if (i % 2 != 0){
            n = 0;
            for (j = 0; j < currentWord.Length; j++){
                word [j] = currentWord.TabWord[j];
                n++;
            }
            for (j = 0; j < n; j++){
                printf("%c", word[n-j-1]);
            }
        } else if (i %2 ==0) {
            //CopyWord();
            for (j = 0; j < currentWord.Length; j++){
                printf("%c", currentWord.TabWord[j]);
            }
        }
        IgnoreBlanks();
        if (currentChar != MARK){
            printf(" ");
        }
        ADVWORD();
        i++;
    }
    printf("\n");
    return 0;
}