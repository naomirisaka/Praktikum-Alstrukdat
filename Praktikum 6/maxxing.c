#include <stdio.h>
#include "stack.h"
#include "boolean.h"

const int MXN = 1e4 + 7;

int find_max(int a, int b){
    return a > b ? a : b;
}

int find_min(int a, int b){
    return a < b ? a : b;
}

int main(){
    // Start code here...
    Stack s;
    int N, min, temp, i, val, len;
    int result[MXN], nums[MXN], left[MXN], right[MXN];
    CreateEmpty(&s);
    scanf("%d", &N);

    min = 1999999999;
    for (i = 0; i < N; i++){
        scanf("%d", &val);
        nums[i] = val;
        min = find_min(min, val);
        
        while (!IsEmpty(s) && nums[InfoTop(s)] >= val){
            Pop(&s, &temp);
            right[temp] = i - 1;
        }
        Push(&s, i);
    }
    while (!IsEmpty(s)){
        Pop(&s, &temp);
        right[temp] = N - 1;
    }

    for (i = N - 1; i >= 0; i--){
        val = nums[i];
        min = find_min(min, val);
        while (!IsEmpty(s) && nums[InfoTop(s)] > val){
            Pop(&s, &temp);
            left[temp] = i + 1;
        }
        Push(&s, i);
    }
    while (!IsEmpty(s)){
        Pop(&s, &temp);
        left[temp] = 0;
    }

    for (i = 0; i < N; i++){
        len = right[i] - left[i] + 1;
        result[len] = find_max(result[len], nums[i]);
    }

    result[N] = min;
    for (i = N - 1; i >= 1; i--){
        result[i] = find_max(result[i], result[i + 1]);
    }

    for (i = 1; i <= N; i++){
        printf("%d", result[i]);
        if (i < N){
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}
