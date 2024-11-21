#include <stdio.h>
#include "boolean.h"
#include "stack.h"

int main(){
    int N, i;
    char ch, c;
    Stack s;
    CreateEmpty(&s);
    scanf("%d", &N);

    for (i = 0; i < N; i++)
    {
        scanf(" %c", &ch);
        if (ch == '(' | ch == '{' | ch == '['){
            Push(&s, ch);
        } else if (ch == ')' | ch == '}' | ch == ']'){
            if ((ch == ')' && InfoTop(s) == '(') |(ch == '}' && InfoTop(s) == '{') | (ch == ']' && InfoTop(s) == '[')){
                Pop(&s, &c);
            } else {
                Push(&s, ch);
            }
        }
    }
    if (IsEmpty(s)){
        printf("Valid\n");
    } else {
        printf("Invalid\n");
    }
    return 0;
}