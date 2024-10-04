#include <stdio.h>
#include "complex.h"
#include <math.h>

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsCOMPLEXValid(float Re, float Im){
/* Mengirim true jika Re dan Im valid untuk membentuk COMPLEX */
/* Dalam konteks kompleks, semua bilangan real adalah valid */
    return true;
}

/* *** Konstruktor: Membentuk sebuah COMPLEX dari komponen-komponennya *** */
void CreateComplex(COMPLEX *C, float Re, float Im){
/* Membentuk sebuah COMPLEX dari komponen-komponennya */
    Real(*C) = Re;
    Imag(*C) = Im; 
}

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaCOMPLEX(COMPLEX *C){
/* I.S. : C tidak terdefinisi */
/* F.S. : C terdefinisi */
/* Proses : Membaca komponen Re dan Im dari pengguna */
    float Re, Im;
    scanf("%f %f", &Re, &Im);
    CreateComplex(C, Re, Im);
}

void TulisCOMPLEX(COMPLEX C){
/* I.S. : C sembarang */
/* F.S. : Nilai C ditulis dengan format "a+bi" atau "a-bi" (tanpa spasi) dan diakhiri newline */
/* Proses : Menulis nilai Re dan Im ke layar */
    if (Imag(C) >= 0){
        printf("%.2f+%.2fi\n", Real(C), Imag(C));
    } else {
        printf("%.2f%.2fi\n", Real(C), Imag(C));
    }
}

/* ***************************************************************** */
/* KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE                         */
/* ***************************************************************** */
COMPLEX AddCOMPLEX(COMPLEX C1, COMPLEX C2){
/* Mengirim hasil penjumlahan C1 + C2 */
    COMPLEX C;
    Real(C) = Real(C1) + Real(C2);
    Imag(C) = Imag(C1) + Imag(C2);
    return C;
}

COMPLEX SubtractCOMPLEX(COMPLEX C1, COMPLEX C2){
/* Mengirim hasil pengurangan C1 - C2 */
    COMPLEX C;
    Real(C) = Real(C1) - Real(C2);
    Imag(C) = Imag(C1) - Imag(C2);
    return C;
}

COMPLEX MultiplyCOMPLEX(COMPLEX C1, COMPLEX C2){
/* Mengirim hasil perkalian C1 * C2 */
/* Rumus: (a + bi) * (c + di) = (ac - bd) + (ad + bc)i */
    COMPLEX C;
    Real(C) = Real(C1)*Real(C2) - Imag(C1)*Imag(C2);
    Imag(C) = Real(C1)*Imag(C2) + Imag(C1)*Real(C2);
    return C;
}

COMPLEX DivideCOMPLEX(COMPLEX C1, COMPLEX C2){
/* Mengirim hasil pembagian C1 / C2 */
/* Rumus: (a + bi) / (c + di) = [(a + bi)(c - di)] / (c^2 + d^2) */
/* Jika denominator pecahan bernilai 0, maka kembalikan nilai 0+0i*/
    COMPLEX C;
    float denom = pow(Real(C2), 2) + pow(Imag(C2), 2); 
    if (denom == 0) {
        Real(C) = 0;
        Imag(C) = 0;
    } else {
        Real(C) = (Real(C1) * Real(C2) + Imag(C1) * Imag(C2)) / denom;  
        Imag(C) = (Imag(C1) * Real(C2) - Real(C1) * Imag(C2)) / denom;  
    }
    return C;    
}

/* ***************************************************************** */
/* KELOMPOK OPERASI LAIN TERHADAP TYPE                               */
/* ***************************************************************** */
float AbsCOMPLEX(COMPLEX C){
/* Mengirim nilai absolut (modulus) dari C */
/* Rumus: |C| = sqrt(Re^2 + Im^2) */
    return sqrt(pow(Real(C), 2) + pow(Imag(C), 2));
}

COMPLEX ConjugateCOMPLEX(COMPLEX C){
/* Mengirim hasil konjugasi dari C */
/* Rumus: Conj(C) = Re - i*Im */
    //if (Imag(C) != 0)
    Imag(C) = -Imag(C); //apa no need? biarin aja double
    return C;
}

/* *** Kelompok Operator Relational *** */
boolean CEQ(COMPLEX C1, COMPLEX C2){
/* Mengirimkan true jika C1 = C2 (Re dan Im sama) */
    return (Real(C1)==Real(C2) && Imag(C1)==Imag(C2));
}

boolean CNEQ(COMPLEX C1, COMPLEX C2){
/* Mengirimkan true jika C1 tidak sama dengan C2 */
    return (!CEQ(C1, C2));
}
/* ***************************************************************** */