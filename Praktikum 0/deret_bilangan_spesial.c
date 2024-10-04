#include <stdio.h>
#include <math.h>

int main(){
    int a, b, i;
    scanf("%d %d", &a, &b);
    i = a;
    printf("%d", i);
    if (i %2 != 0){
        i += 1;
        if (i < b){
            printf (" %d", i);
        }
    }
    while (i < b){
        i *= 2;
        if (i < b){
            printf(" ");
            printf ("%d", i);
        }
    }
    printf("\n");
    return 0;
}