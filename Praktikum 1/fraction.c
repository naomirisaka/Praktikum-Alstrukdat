#include <stdio.h>
#include <string.h>
#include <math.h>
#include "fraction.h"

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsFRACTIONValid(int N, int D){
/* Mengirim TRUE jika pecahan valid */
    return (D != 0);
}

/* *** Konstruktor: Membentuk FRACTION F dari komponen-komponennya *** */
void CreateFRACTION(FRACTION *F, int N, int R){
/* Membentuk sebuah FRACTION yang valid */
/* Prekondisi : N, R valid */
    Numerator(*F) = N;
    Denominator(*F) = R;
}

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void ReadFRACTION(FRACTION *F){
/**
 * I.S. : F tidak terdefinisi
 * F.S. : F terdefinisi dan merupakan FRACTION yang valid
 * Proses : Mengulangi membaca komponen N, R sehingga membentuk F
 *  - Pembacaan dilakukan dengan mengetikkan komponen N, R dalam
 *    1 baris, dipisah spasi, diakhiri enter.
 *  - Jika FRACTION tidak valid, maka berikan pesan: "FRACTION tidak valid"
 *    dengan newline, pembacaan diulangi hingga didapat FRACTION yang valid.
 */
    int N, D, f;
    scanf("%d %d", &N, &D);    // never gabung scanf with \n
    while (!IsFRACTIONValid(N, D)){
        printf("FRACTION tidak valid\n");
        scanf("%d %d", &N, &D);
    }
    CreateFRACTION(F, N, D);
   /* f = gcd(N, D);
    n = N/f;
    d = D/f;
    CreateFRACTION (F, n, d); */
}

void WriteFRACTION(FRACTION F){
/**
 * I.S. : F sembarang
 * F.S. : Nilai F ditulis dengan format "N/R"
 * Proses : Penulisan tanpa spasi, enter, atau karakter lain di depan, 
 * belakang, atau di antaranya
 * NOTE: hasil dalam bentuk paling sederhana
 */

/* ***************************************************************** */
/* KELOMPOK OPERASI DASAR TERHADAP TYPE                              */
/* ***************************************************************** */
/* NOTE: untuk hasil FRACTION = 0, maka kembalikan 0/1 */
    F = SimplifyFRACTION(F);
    printf("%d/%d", Numerator(F), Denominator(F));
    /*if (Numerator(F)==0){
        printf("0/1\n");
    } else {
        if (Numerator(F) < 0 && Denominator(F) <0){
            Numerator(F) *= (-1);
            Denominator(F) *= (-1);
        }
        F = SimplifyFRACTION(F);
        printf("%d/%d", Numerator(F), Denominator(F));
    }*/
}

FRACTION AddFRACTION(FRACTION F1, FRACTION F2){
/* Mengirim hasil penjumlahan F1 + F2 */
/* NOTE: hasil dalam bentuk paling sederhana */
    FRACTION F3;
    Denominator(F3) = Denominator(F1) * Denominator(F2);
    Numerator(F3) = (Numerator(F1)*Denominator(F2)) + (Numerator(F2)*Denominator(F1));
    return (SimplifyFRACTION(F3));
}

FRACTION SubtractFRACTION(FRACTION F1, FRACTION F2){
/* Mengirim hasil pengurangan F1 - F2 */
/* NOTE: hasil dalam bentuk paling sederhana */
    FRACTION F3;
    Denominator(F3) = Denominator (F1)*Denominator(F2);
    Numerator(F3) = (Numerator(F1)*Denominator(F2)) - (Numerator(F2)*Denominator(F1));
    return (SimplifyFRACTION(F3));
}

FRACTION MultiplyFRACTION(FRACTION F1, FRACTION F2){
/* Mengirim hasil perkalian F1 * F2 */
/* NOTE: hasil dalam bentuk paling sederhana */
    FRACTION F3;
    Denominator(F3) = Denominator (F1)*Denominator(F2);
    Numerator(F3) = Numerator(F1)*Numerator(F2);
    return (SimplifyFRACTION(F3));
}

FRACTION DivideFRACTION(FRACTION F1, FRACTION F2){
/* Mengirim hasil pembagian F1 / F2 */
/* Prekondisi: F2 tidak nol */
/* NOTE: hasil dalam bentuk paling sederhana */
    FRACTION F3;
    Denominator(F3) = Denominator (F1)*Numerator(F2);
    Numerator(F3) = Numerator(F1)*Denominator(F2);
    return (SimplifyFRACTION(F3));
}

FRACTION MultiplyNumberFRACTION(int n, FRACTION F1){
/* Mengirim hasil perkalian n * F1 */
/* NOTE: hasil dalam bentuk paling sederhana */
    FRACTION F3;
    Denominator(F3) = Denominator(F1);
    Numerator(F3) = n*Numerator(F1);
    return (SimplifyFRACTION(F3));
}

/* ***************************************************************** */
/* KELOMPOK OPERASI LAIN TERHADAP TYPE                               */
/* ***************************************************************** */
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
FRACTION SimplifyFRACTION(FRACTION F){
/* Mengembalikan FRACTION dalam bentuk sederhana */
/* NOTE: pastikan hanya numerator yang memiliki nilai negatif */
    int gcd_value = gcd(abs(Numerator(F)), abs(Denominator(F)));
    Numerator(F) /= gcd_value; 
    Denominator(F) /= gcd_value;
    if (Denominator(F) < 0){
        Numerator(F) *= (-1);
        Denominator(F) *= (-1);
    }
    if (Numerator(F) == 0){
        Numerator(F) = 0;
        Denominator(F) = 1;
    }
    return F;
} 

float ToDecimal(FRACTION F){
/* Mengonversi FRACTION ke bentuk desimal */
    return((float)Numerator(F) / (float)Denominator(F));
}


/*
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
*/
