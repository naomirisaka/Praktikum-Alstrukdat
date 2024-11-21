#include "boolean.h"
#include "mesinkata.h"
#include <stdio.h>

boolean isWordEqual (Word w1, Word w2){
    int i;
    if (w1.Length != w2.Length){
        return false;
    } else {
        for (i = 0; i < w1.Length; i++){
            if (w1.TabWord[i] != w2.TabWord[i]){
                return false;
            }
        }
        return true;
    }
}

Word str_to_num(char str [], int length){
    int i;
    Word num;
    num.Length = length;
    for (i = 0; i < length; i++){
        num.TabWord[i] = str[i];
    }
    return num;
}

int main(){
    Word nol, satu, dua, tiga, empat, lima, enam, tujuh, delapan, sembilan, sepuluh;
    Word sebelas, belas, puluh, seratus, ratus;
    int num, i;
    boolean is_num, print_num, blank_needed;
    
    char c_nol[50] = "nol";
    nol = str_to_num(c_nol, 3);
    
    char c_satu[50] = "satu";
    satu = str_to_num(c_satu, 4);

    char c_dua[50] = "dua";
    dua = str_to_num(c_dua, 3);

    char c_tiga[50] = "tiga";
    tiga = str_to_num(c_tiga, 4);

    char c_empat[50] = "empat";
    empat = str_to_num(c_empat, 5); 

    char c_lima[50] = "lima";
    lima = str_to_num(c_lima, 4);

    char c_enam[50] = "enam";
    enam = str_to_num(c_enam, 4);

    char c_tujuh[50] = "tujuh";
    tujuh = str_to_num(c_tujuh, 5);
    
    char c_delapan[50] = "delapan";
    delapan = str_to_num(c_delapan, 7);

    char c_sembilan[50] = "sembilan";
    sembilan = str_to_num(c_sembilan, 8);

    char c_sepuluh[50] = "sepuluh";
    sepuluh = str_to_num(c_sepuluh, 7);

    char c_sebelas[50] = "sebelas";
    sebelas = str_to_num(c_sebelas, 7);

    char c_belas[50] = "belas";
    belas = str_to_num(c_belas, 5);

    char c_puluh[50] = "puluh";
    puluh = str_to_num(c_puluh, 5);

    char c_seratus[50] = "seratus";
    seratus = str_to_num(c_seratus, 7);

    char c_ratus[50] = "ratus";
    ratus = str_to_num(c_ratus, 5);

    STARTWORD();

    num = -1;
    blank_needed = false;  
    while (!EndWord){
        is_num = false;
        print_num = false; 
        
        if (isWordEqual (nol, currentWord)){
            if (num == -1){
                num = 0;
            }
            is_num = true;
        } else if (isWordEqual(satu, currentWord)){
            if (num == -1){
                num = 0;
            }
            num += 1;
            is_num = true;
        } else if (isWordEqual(dua, currentWord)){
            if (num == -1){
                num = 0;
            }
            num += 2;
            is_num = true;
        } else if (isWordEqual(tiga, currentWord)){
            if (num == -1){
                num = 0;
            }
            num += 3;
            is_num = true;
        } else if (isWordEqual(empat, currentWord)){
            if (num == -1){
                num = 0;
            }
            num += 4;
            is_num = true;
        } else if (isWordEqual(lima, currentWord)){
            if (num == -1){
                num = 0;
            }
            num += 5;
            is_num = true;
        } else if (isWordEqual(enam, currentWord)){
            if (num == -1){
                num = 0;
            }
            num += 6;
            is_num = true;
        } else if (isWordEqual(tujuh, currentWord)){
            if (num == -1){
                num = 0;
            }
            num += 7;
            is_num = true;
        } else if (isWordEqual(delapan, currentWord)){
            if (num == -1){
                num = 0;
            }
            num += 8;
            is_num = true;
        } else if (isWordEqual(sembilan, currentWord)){
            if (num == -1){
                num = 0;
            }
            num += 9;
            is_num = true;
        } else if (isWordEqual(sepuluh, currentWord)){
            if (num == -1){
                num = 0;
            }
            num += 10;
            is_num = true;
        } else if (isWordEqual(sebelas, currentWord)){
            if (num == -1){
                num = 0;
            }
            num += 11;
            is_num = true;
        } else if (isWordEqual(belas, currentWord)){
            if (num == -1){
                num = 0;
            }
            num += 10;
            is_num = true;
        } else if (isWordEqual(puluh, currentWord)){
            num += 10 * (num % 10) - (num % 10);
            is_num = true;
        } else if (isWordEqual(seratus, currentWord)){
            if (num == -1){
                num = 0;
            }
            num += 100;
            is_num = true;
        }  else if (isWordEqual(ratus, currentWord)){
            num += 100 * (num % 100) - (num % 100); 
            is_num = true;
        } else {
            print_num = true;
        }

        if (print_num && num >= 0){
            if (blank_needed){
                printf(" ");
            }
            printf("%d", num);
            blank_needed = true;
            num = -1;
            print_num = false;  // Ensure print_num is reset
        }

        if (!is_num){
            if (blank_needed){
                printf(" ");
            }   
            for (i = 0; i < currentWord.Length; i++){
                printf("%c", currentWord.TabWord[i]);
            }
            blank_needed = true;
        }
        ADVWORD();
    }

    if (num >= 0){
        if (blank_needed){
            printf(" ");
        }
        printf("%d", num);
    }
    printf("\n");
    return 0;
}