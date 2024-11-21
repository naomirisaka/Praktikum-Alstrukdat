#include <stdio.h>
#include "boolean.h"
#include "stack.h"

int main(){
    Stack decode;
    int n, i, k, count, pow_val, stack_len;
    char ch, val, in_bracket;
    
    CreateEmpty(&decode);
    scanf("%d", &n);

    for (i = 0; i < n; i++){
        scanf(" %c", &ch);
        if (ch == ']'){
            char arr[MaxEl];
            int arr_len = 0;
            while (InfoTop(decode) != '['){
                Pop(&decode, &arr[arr_len]);
                arr_len++;
            }
            arr[arr_len] = '\0';
            Pop(&decode, &in_bracket);

            k = 0;
            count = 0;
            while (InfoTop(decode) >= '0' && InfoTop(decode) <= '9'){
                Pop(&decode, &val);
                pow_val = 1;
                for (int j = 0; j < count; j++){
                    pow_val *= 10;
                }
                k += (val - '0') * pow_val;
                count++;
            }
            for (int j = 0; j < k; j++){
                for (int m = arr_len - 1; m >= 0; m--){
                    Push(&decode, arr[m]);
                }
            }

        }
        else {
            Push(&decode, ch);
        }
    }

    stack_len = Top(decode);
    for (i = 0; i < stack_len + 1; i++){
        printf("%c", decode.T[i]);
    }
    printf("\n");
    return 0;
}