#include <stdio.h>
#include "complex.h"

int main(){
    COMPLEX C1, C2, C_add, C_sub, C_mul, C_div, C_conj;
    boolean C_eq, C_neq;

    printf("C1: ");
    BacaCOMPLEX(&C1);
    TulisCOMPLEX(C1);
    printf("\nC2: "); // make this one minus
    BacaCOMPLEX(&C2);
    TulisCOMPLEX(C2);

    C_add = AddCOMPLEX(C1, C2);
    printf("\nC1 + C2: ");
    TulisCOMPLEX(C_add);
    
    C_sub = SubtractCOMPLEX(C1, C2);
    printf("\nC1 - C2: ");
    TulisCOMPLEX(C_sub);

    C_mul = MultiplyCOMPLEX(C1, C2);
    printf("\nC1 * C2: ");
    TulisCOMPLEX(C_mul);

    C_div = DivideCOMPLEX(C1, C2);
    printf("\nC1 / C2: ");
    TulisCOMPLEX(C_div);

    printf("\nNilai absolut C1: %.2f", AbsCOMPLEX(C1));

    C_conj = ConjugateCOMPLEX(C1);
    printf("\nKonjugasi C1: ");
    TulisCOMPLEX(C_conj);

    if (CEQ(C1,C2)){
        printf("\nC1 & C2 sama");
    } else {
        printf("\nC1 & C2 tidak sama");}

    printf("\n");
    return 0;
}