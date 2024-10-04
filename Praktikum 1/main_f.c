#include <stdio.h>
#include <string.h>
#include <math.h>
#include "fraction.h"

int main(){
    FRACTION F1, F2, F_add, F_sub, F_mul, F_div, F_muln;
    int n;
    float decimal;
    ReadFRACTION(&F1);
    WriteFRACTION(F1);
    ReadFRACTION(&F2);
    WriteFRACTION(F2);
    F_add = AddFRACTION(F1,F2);
    printf("F1 + F2 = ");
    WriteFRACTION(F_add);
    F_sub = SubtractFRACTION(F1,F2);
    printf("F1 - F2 = ");
    WriteFRACTION(F_sub);
    F_mul = MultiplyFRACTION(F1,F2);
    printf("F1 * F2 = ");
    WriteFRACTION(F_mul);
    F_div = DivideFRACTION(F1,F2);
    printf("F1 / F2 = ");
    WriteFRACTION(F_div);
    printf("n: ");
    scanf("%d", &n);
    F_muln = MultiplyNumberFRACTION(n,F1);
    printf("n * F1 = ");
    WriteFRACTION(F_muln);
    decimal = ToDecimal(F1);
    printf("F1 dalam desimal: %f\n", decimal);
    return 0;
}