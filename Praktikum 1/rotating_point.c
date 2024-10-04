#include <stdio.h>
#include <math.h>

#include "point.h"
#include "complex.h"
#include "rotating_point.h"

/* Catatan: Hasil perkalian float dan int adalah float*/

/* Fungsi untuk menghitung perpangkatan bilangan kompleks */
/* Formula: Bilangan kompleks dikalikan dirinya sendiri sebanyak P kali */
COMPLEX PowerCOMPLEX(COMPLEX C, int p){
    COMPLEX temp, result;
    int i;
    Real(result) = 1.00;
    Imag(result) = 0.00;
    for (i = 0; i < p; i++){
        Real(temp) = Real(result)*Real(C) - Imag(result)*Imag(C);
        Imag(temp) = Real(result)*Imag(C) + Imag(result)*Real(C);
        result = temp;
        //result = MultiplyCOMPLEX(result,C);
        }
    return result;
}

void TransformPointByComplexPower(POINT *P, COMPLEX C, int n){
    int i;
    POINT P_new;
    COMPLEX C_pow;
    if (n==0){
        printf("Titik keluar dari lingkaran pada iterasi ke 0");
        return;
    }
    for (i=0; i<=n; i++){
        C_pow = PowerCOMPLEX (C, i+1);
        Absis(P_new) = Absis(*P)*Real(C_pow) - Ordinat(*P)*Imag(C_pow);
        Ordinat (P_new) = Absis(*P)*Imag(C_pow) + Ordinat(*P)*Real(C_pow);
        Absis(*P) = Absis(P_new);
        Ordinat(*P) = Ordinat(P_new);
        if ((pow(Absis(*P),2) + pow(Ordinat(*P),2)) > 1){
            printf("Titik keluar dari lingkaran pada iterasi ke %d", i+1);
            return;}
    }
    printf("Titik tetap berada di dalam lingkaran setelah %d iterasi", n);
}

/*int main(){
    POINT P;
    COMPLEX C;
    int n;
    BacaPOINT(&P);
    BacaCOMPLEX(&C);
    scanf("%d", &n);
    while (n < 0){
        scanf("%d", &n);
    }
    TransformPointByComplexPower(&P, C, n);
    return 0;
} */
