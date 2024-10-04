#include <stdio.h>
#include <string.h>
#include <math.h>
#include "point.h"      //write in gcc -o as well bcs we need the .c, if u udh include .c here (only do if the file doesn't have .h), no need
#include "circle.h" 

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsCIRCLEValid(float X, float Y, float R){
/* Mengirim TRUE jika X, Y, R dapat membentuk Lingkaran C yang valid */
    return R > 0;
}

/* *** Konstruktor: Membentuk Lingkaran C dari titik pusat dan radius *** */
void CreateCIRCLE(CIRCLE *C, float X, float Y, float R){
/* Membentuk sebuah CIRCLE dari komponen-komponen yang valid */
/* Prekondisi : X, Y, R, valid */
    POINT Center;
    CreatePoint(&Center(*C), X, Y);
    Radius (*C) = R; 
}

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void ReadCIRCLE(CIRCLE *C){
/**
 * I.S. : C tidak terdefinisi
 * F.S. : C terdefinisi dan merupakan CIRCLE yang valid
 * Proses : Mengulangi membaca komponen X, Y, R sehingga membentuk C
 *  - Pembacaan dilakukan dengan mengetikkan komponen X, Y, R dalam
 *    1 baris, dipisah spasi, diakhiri enter.
 *  - Jika CIRCLE tidak valid, maka berikan pesan: "CIRCLE tidak valid"
 *    dengan newline, pembacaan diulangi hingga didapat CIRCLE yang valid.
 */
    float X, Y, R;
    scanf("%f %f %f", &X, &Y, &R);
    while (!IsCIRCLEValid(X, Y, R)){
        printf("CIRCLE tidak valid\n");
        scanf("%f %f %f", &X, &Y, &R);
    }
    CreateCIRCLE(C, X, Y, R);   // ga pake &C bcs dari pointer (*C) ke pointer (*C)
}

void WriteCIRCLE(CIRCLE C){
/**
 * I.S. : C sembarang
 * F.S. : Nilai C ditulis dengan format "P(X,Y) r=R", ex: P(1,1) r=5
 * Proses : Penulisan tanpa spasi, enter, atau karakter lain di depan, 
 * belakang, atau di antaranya
 */
    printf("P(%.2f,%.2f) r=%.2f", (Absis(Center(C))), (Ordinat(Center(C))), Radius(C)); 
}

/* ***************************************************************** */
/* KELOMPOK OPERASI GEOMETRI TERHADAP TYPE                           */
/* ***************************************************************** */
float Circumference(CIRCLE C){
/* Menghitung keliling lingkaran: K = 2 * π * r, π = 3.14 */
    return (2 * 3.14 * Radius(C));
}

float Area(CIRCLE C){
/* Menghitung luas lingkaran: A = π * r^2, π = 3.14 */
    return (3.14 * pow(Radius(C),2));
}

/* ***************************************************************** */
/* KELOMPOK OPERASI LAIN TERHADAP TYPE                               */
/* ***************************************************************** */
boolean IsPOINTInsideCIRCLE(CIRCLE C, POINT P){
/* Mengirim true jika titik P berada di dalam lingkaran C */
    float kuad_ling = sqrt(pow((Absis(Center(C))-Absis(P)),2) + pow(Ordinat(Center(C))-Ordinat(P),2));
    return (kuad_ling < Radius(C));
}

boolean IsPOINTInEdgeCIRCLE(CIRCLE C, POINT P){
/* Mengirim true jika titik P berada di tepi lingkaran C */
/* HINT: Gunakan toleransi kecil untuk komparasi float */
    float kuad_ling = sqrt(pow((Absis(Center(C))-Absis(P)),2) + pow(Ordinat(Center(C))-Ordinat(P),2));
    return (fabs(kuad_ling - Radius(C) < 1e-5));   // fabs is abs but for float
}

boolean IsCIRCLEInsideCIRCLE(CIRCLE C1, CIRCLE C2){
/* Mengirim true jika C1 di dalam C2 atau C2 di dalam C1 */
/* NOTE: Tidak berpotongan/ bersinggungan */\
    float distance = sqrt(pow(Absis(Center(C2))-Absis(Center(C1)),2) + pow(Ordinat(Center(C2))-Ordinat(Center(C1)),2));
    return (distance + Radius(C1) < Radius(C2)) || (distance + Radius(C2) < Radius(C1));
}


boolean IsCIRCLESTangents(CIRCLE C1, CIRCLE C2){
/* Mengirim true jika C1 bersinggungan di 1 titik dengan C2 */
/**
 * HINT: Terdapat 2 Kemungkinan:
 *  1. Bersinggungan dalam
 *  2. Bersinggungan luar
 */
    float distance = sqrt(pow(Absis(Center(C2))-Absis(Center(C1)),2) + pow(Ordinat(Center(C2))-Ordinat(Center(C1)),2));
    return (fabs(distance - fabs(Radius(C1) - Radius(C2))) < 1e-5 || fabs(distance - (Radius(C1) + Radius(C2))) < 1e-5); // don't use == bcs decimals

}

boolean IsCIRCLESIntersects(CIRCLE C1, CIRCLE C2){
/* Mengirim true jika C1 berpotongan di 2 titik dengan C2 */
    float distance = sqrt(pow(Absis(Center(C2))-Absis(Center(C1)),2) + pow(Ordinat(Center(C2))-Ordinat(Center(C1)),2));
    return (distance > fabs(Radius(C1)-Radius(C2)) && distance < (Radius(C1)+Radius(C2)));
}

/* ***************************************************************** */

/*
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

*/