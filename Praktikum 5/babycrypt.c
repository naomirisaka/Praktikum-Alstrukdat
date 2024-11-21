#include <stdio.h>
#include "mesinkata.h"
#include <stdlib.h>

int main(){
    int i, idx, shift;
    boolean char_found;
    char alphabet[26] = "abcdefghijklmnopqrstuvwxyz";
    char caps[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    START();
    shift = 0;
    while (currentChar != BLANK){
        shift = shift * 10 + (currentChar - '0');
        ADV();
    }
    shift %= 26;
    IgnoreBlanks();
    while (currentChar != MARK){
        if (currentChar == BLANK){
            printf(" ");
        } else {
            char_found = false;
            for (i = 0; i < 26; i++){
                if (currentChar == alphabet[i]){
                    char_found = true;
                    idx = (i - shift + 26) % 26;
                    printf("%c", alphabet[idx]);
                    break;
                } else if (currentChar == caps[i]){
                    char_found = true;
                    idx = (i - shift + 26) % 26;
                    printf("%c", caps[idx]);
                    break;
                }
            }
            if (!char_found){
                printf("%c", currentChar);
            }
        }
        ADV();
    }
    printf("\n");
    return 0;
}