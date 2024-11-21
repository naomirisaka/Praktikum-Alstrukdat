#include <stdio.h>
#include "boolean.h"
#include "stack.h"

// HINT: Gunakan (c - '0') untuk mengubah character ke angka

int main(){
    int N, i, j, val1, val2, val;
    long long vall;
    char ch;
    Stack s;
    CreateEmpty(&s);

    scanf("%d", &N);
    if (N <= 0 | N > 100){
        return 1;
    } else {
        for (i = 0; i < N; i++){
            scanf(" %c", &ch);
            if (ch == '+'){ 
                Pop(&s, &val2);
                Pop(&s, &val1);
                val = val1 + val2;
                Push(&s, val1);
                Push(&s, val2);
                Push(&s, val);
            } else if (ch == 'X'){
                Pop(&s, &val2);
            } else if (ch == 'S'){
                val1 = 0;
                while (!IsEmpty(s)){
                    Pop(&s, &val2);
                    val1 += val2;
                }
                Push (&s, val1);
            } else if (ch == 'A'){
                val1 = 0;
                j = 0;
                while (!IsEmpty(s)){
                    Pop(&s, &val2);
                    val1 += val2;
                    j++;
                }
                if (j > 0){
                    val1 /= j;
                    Push (&s, val1);
                }
            } else if (ch - '0' > 0){
                val = ch - '0';
                Push(&s, val);
            }
        }
        vall = 0;
        while (!IsEmpty(s)){
            Pop(&s, &val);
            vall += val;
        }
        printf("%lld\n", vall);
        return 0;
    }
}