#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "mesinkata.h"

boolean is_valid_oktet(Word w) {
    int num;
    if (w.Length > 3 || w.Length == 0 || (w.Length > 1 && w.TabWord[0] == '0')){
        return false;
    }
    num = 0;
    for (int i = 0; i < w.Length; i++) {
        if (w.TabWord[i] < '0' || w.TabWord[i] > '9'){
            return false;
        }
        num = num * 10 + (w.TabWord[i] - '0');
    }
    return (num >= 0 && num <= 255);
}

boolean is_IPv4Lay(Word w) {
    int at_count = 0;
    Word oktet;
    oktet.Length = 0;
    for (int i = 0; i < w.Length; i++) {
        if (w.TabWord[i] == '@') {
            if (!is_valid_oktet(oktet)){
                return false;
            }
            oktet.Length = 0;
            at_count++;
        } else {
            if (w.TabWord[i] < '0' || w.TabWord[i] > '9'){
                return false;
            } 
            oktet.TabWord[oktet.Length++] = w.TabWord[i];
        }
    }
    return (at_count == 3 && is_valid_oktet(oktet));
}

int main() {
    STARTWORD();
    while (!EndWord) {
        if (is_IPv4Lay(currentWord)) {
            printf("4Lay");
        } else {
            printf("ewh");
        }
        ADVWORD();
        if (!EndWord){
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}
