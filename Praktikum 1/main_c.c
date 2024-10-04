#include <stdio.h>
#include <string.h>
#include <math.h>
#include "circle.h"
#include "point.h"

int main(){
    CIRCLE C1, C2;
    POINT P;
    float kel, luas;
    ReadCIRCLE(&C1);
    WriteCIRCLE(C1);
    kel = Circumference(C1);
    printf("Keliling: %f\n", kel);
    luas = Area(C1);
    printf("Luas: %f\n", luas);
    printf("P: ");
    BacaPOINT(&P);
    if (IsPOINTInsideCIRCLE(C1, P)){
        printf("Titik ada dalam lingkaran\n");
    } else if (IsPOINTInEdgeCIRCLE(C1, P)) {
        printf("Titik ada di pinggir lingkaran\n");
    } else {
        printf("Titik ada di luar lingkaran\n");
    }
    printf("Lingkaran 2: ");
    ReadCIRCLE(&C2);
    WriteCIRCLE(C2);
    if (IsCIRCLEInsideCIRCLE (C1, C2)){
        printf("Lingkaran berada dalam lingkaran lain\n");
    } else if (IsCIRCLESTangents (C1, C2)){
        printf("Lingkaran bersinggungan dengan lingkaran lain\n");
    } else if (IsCIRCLESIntersects (C1, C2)){
        printf("Lingkaran berpotongan dengan lingkaran lain\n");
    } else {
        printf("Lingkaran saling terpisah\n");
    }
    return 0;
}