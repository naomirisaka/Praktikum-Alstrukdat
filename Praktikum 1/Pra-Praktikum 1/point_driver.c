#include <stdio.h>
#include "point.h"

int main() {
    POINT P1, P2, P1_NextX, P1_NextY, P1_PlusDelta, P1_Mirror;
    float deltaX, deltaY, angle, SbX;
    
    printf("P1: ");
    BacaPOINT(&P1);
    TulisPOINT(P1);
    printf("\nP2: ");
    BacaPOINT(&P2);
    TulisPOINT(P2);

    if (EQ(P1,P2)){
        printf("\nP1 & P2 sama");
    } else {
        printf("\nP1 & P2 tidak sama");}

    if(IsOrigin(P1)){
        printf("\nP1 adalah titik origin");
    } else {
        printf("\nP1 bukan titik origin");
    }

    if(IsOnSbX(P1)){
        printf("\nP1 terletak pada sumbu X");
    } else {
        printf("\nP1 tidak terletak pada sumbu X");
    }

    if(IsOnSbY(P1)){
        printf("\nP1 terletak pada sumbu Y");
    } else {
        printf("\nP1 tidak terletak pada sumbu Y");
    }

    printf("\nKuadran P1: %d", Kuadran(P1));

    P1_NextX = NextX(P1);
    printf("\nJika x pada P1 +1: ");
    TulisPOINT(P1_NextX);

    P1_NextY = NextY(P1);
    printf("\nJika y pada P1 +1: ");
    TulisPOINT(P1_NextY);

    printf("\nDelta X untuk P1: ");
    scanf("%f", &deltaX);
    printf("Delta Y untuk P1: ");
    scanf("%f", &deltaY);
    P1_PlusDelta = PlusDelta(P1, deltaX, deltaY);
    printf("Jika x pada P1 +1: ");
    TulisPOINT(P1_PlusDelta);

    printf("\nP1 setelah dicerminkan terhadap sumbu X: "); 
    SbX = true;
    P1_Mirror = MirrorOf(P1, SbX);
    TulisPOINT(P1_Mirror);

    printf("\nJarak P1 ke origin: %.2f", Jarak0(P1));

    printf("\nJarak P1 dan P2: %.2f", Panjang(P1, P2));

    printf("\nSudut rotasi P1: ");
    scanf("%f", &angle);
    Putar(&P1, angle);
    printf("P1 setelah rotasi: ");
    TulisPOINT(P1);

    printf("\nP1 setelah dicerminkan terhadap sumbu Y (false untuk sumbu X): "); 
    SbX = false;
    Mirror(&P1, SbX);
    TulisPOINT(P1);

    printf("\nPergeseran pada sumbu X: ");
    scanf("%f", &deltaX);
    printf("Pergeseran pada sumbu Y: ");
    scanf("%f", &deltaY);
    Geser(&P1, deltaX, deltaY);
    printf("P1 setelah translasi: ");
    TulisPOINT(P1);
    
    GeserKeSbX(&P1);
    printf("\nP1 setelah digeser ke sumbu X: ");
    TulisPOINT(P1);
    
    GeserKeSbY(&P1);
    printf("\nP1 setelah digeser ke sumbu Y: ");
    TulisPOINT(P1);

    printf("\nPers. linear yang melalui P1 dan P2: ");
    PersamaanLinearDuaVariabel(P1, P2);

    return 0;
}
