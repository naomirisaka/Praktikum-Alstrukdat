#include "matrix.h"
#include "boolean.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void createMatrix(int nRows, int nCols, Matrix *m){
/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */
    int i, j;
    ROW_EFF(*m) = nRows;
    COL_EFF(*m) = nCols;
    for (i = 0; i < nRows; i++){
        for (j = 0; j < nCols; j++){
            ELMT(*m, i, j) = 0;
        }
    }
}

/* *** Selektor "Dunia Matrix" *** */
boolean isMatrixIdxValid(int i, int j){
/* Mengirimkan true jika i, j adalah index yang valid untuk matriks apa pun */
    return (i >= 0 && i < ROW_CAP && j >= 0 && j < COL_CAP);
}

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
IdxType getLastIdxRow(Matrix m){
/* Mengirimkan Index baris terbesar m */
    return (ROW_EFF(m)-1);
}
IdxType getLastIdxCol(Matrix m){
/* Mengirimkan Index kolom terbesar m */
    return (COL_EFF(m)-1);
}
boolean isIdxEff(Matrix m, IdxType i, IdxType j){
/* Mengirimkan true jika i, j adalah Index efektif bagi m */
    return (i >= 0 && i < ROW_EFF(m) && j >= 0 && j < COL_EFF(m));
}
ElType getElmtDiagonal(Matrix m, IdxType i){
/* Mengirimkan elemen m(i,i) */
    if (isIdxEff(m, i, i)){
        return (ELMT(m, i, i));}
}

/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mOut){
/* Melakukan assignment mOut <- mIn */
    int i, j;
    createMatrix(ROW_EFF(mIn), COL_EFF(mIn), mOut);
    for (i = 0; i < ROW_EFF(*mOut); i++){
        for (j = 0; j < COL_EFF(*mOut); j++){
            ELMT(*mOut, i, j) = ELMT(mIn, i, j);
        }
    }
}

/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrix(Matrix *m, int nRow, int nCol){
/* I.S. isIdxValid(nRow,nCol) */
/* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
/* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
    int i, j;
    createMatrix(nRow, nCol, m);
    if (isMatrixIdxValid(nRow-1, nCol-1)){
        for (i = 0; i < nRow; i++){
            for (j = 0; j < nCol; j++){
                scanf("%d", &ELMT(*m, i, j));
            }
        }
    }
}
void displayMatrix(Matrix m){
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi. Baris terakhir tidak diakhiri dengan newline */
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
    int i, j;
    for (i = 0; i < ROW_EFF(m); i++){
        for (j = 0; j < COL_EFF(m); j++){
            printf("%d", ELMT(m, i, j));
            if (j != COL_EFF(m)-1){
                printf(" ");
            }
        }
        if (i != ROW_EFF(m)-1){
            printf("\n");
        }
    }
}

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
Matrix addMatrix(Matrix m1, Matrix m2){
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil penjumlahan matriks: m1 + m2 */
    int i, j;
    Matrix m3;
    if (isMatrixSizeEqual(m1, m2)){
        createMatrix(ROW_EFF(m1), COL_EFF(m1), &m3);
        for (i = 0; i < ROW_EFF(m3); i++){
            for (j = 0; j < COL_EFF(m3); j++){
                ELMT(m3, i, j) = ELMT(m1, i, j) + ELMT (m2, i, j);
            }
        }
    }
    return m3;
}
Matrix subtractMatrix(Matrix m1, Matrix m2){
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil pengurangan matriks: salinan m1 – m2 */
    int i, j;
    Matrix m3;
    if (isMatrixSizeEqual(m1, m2)){
        createMatrix(ROW_EFF(m1), COL_EFF(m1), &m3);
        for (i = 0; i < ROW_EFF(m3); i++){
            for (j = 0; j < COL_EFF(m3); j++){
                ELMT(m3, i, j) = ELMT(m1, i, j) - ELMT (m2, i, j);
            }
        }
    }
    return m3;
}
Matrix multiplyMatrix(Matrix m1, Matrix m2){
/* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
/* Mengirim hasil perkalian matriks: salinan m1 * m2 */
    int i, j, k;
    Matrix m3;
    if (COL_EFF(m1) == ROW_EFF(m2)){
        createMatrix(ROW_EFF(m1), COL_EFF(m2), &m3);
        for (i = 0; i < ROW_EFF(m1); i++){
            for (j = 0; j < COL_EFF(m2); j++){
                for (k = 0; k < COL_EFF(m1); k++){
                    ELMT(m3, i, j) += ELMT(m1, i, k) * ELMT(m2, k, j);
                }
            }
        }
    }
    return m3;
}
Matrix multiplyByConst(Matrix m, ElType x){
/* Mengirim hasil perkalian setiap elemen m dengan x */
    int i, j;
    Matrix m3;
    createMatrix(ROW_EFF(m), COL_EFF(m), &m3);
    for (i = 0; i < ROW_EFF(m); i++){
        for (j = 0; j < COL_EFF(m); j++){
            ELMT(m3, i, j) = ELMT(m, i, j) * x;
        }
    }
    return m3;
}
void pMultiplyByConst(Matrix *m, ElType k){
/* I.S. m terdefinisi, k terdefinisi */
/* F.S. Mengalikan setiap elemen m dengan k */
    int i, j;
    for (i = 0; i < ROW_EFF(*m); i++){
        for (j = 0; j < COL_EFF(*m); j++){
            ELMT(*m, i, j) *= k;
        }
    }
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
boolean isMatrixEqual(Matrix m1, Matrix m2){
/* Mengirimkan true jika m1 = m2, yaitu count(m1) = count(m2) dan */
/* untuk setiap i,j yang merupakan Index baris dan kolom m1(i,j) = m2(i,j) */
/* Juga merupakan strong eq karena getLastIdxCol(m1) = getLastIdxCol(m2) */
    if (!isMatrixSizeEqual(m1,m2)){
        return false;
    } else {
        int i, j;
        for (i = 0; i < ROW_EFF(m1); i++){
            for (j = 0; j < COL_EFF(m1); j++){
                if (ELMT(m1, i, j) != ELMT(m2, i, j)){
                    return false;
                }
            }
        }
        return true;
    }
}
boolean isMatrixNotEqual(Matrix m1, Matrix m2){
/* Mengirimkan true jika m1 tidak sama dengan m2 */
    return (!isMatrixEqual(m1, m2));
}
boolean isMatrixSizeEqual(Matrix m1, Matrix m2){
/* Mengirimkan true jika ukuran efektif matriks m1 sama dengan ukuran efektif m2 */
/* yaitu RowEff(m1) = RowEff (m2) dan ColEff (m1) = ColEff (m2) */
    return (ROW_EFF(m1) == ROW_EFF(m2) && COL_EFF(m1) == COL_EFF(m2));
}

/* ********** Operasi lain ********** */
int countElmt(Matrix m){
/* Mengirimkan banyaknya elemen m */
    return (ROW_EFF(m)*COL_EFF(m));
}

/* ********** KELOMPOK TEST TERHADAP Matrix ********** */
boolean isSquare(Matrix m){
/* Mengirimkan true jika m adalah matriks dg ukuran baris dan kolom sama */
    return (ROW_EFF(m) == COL_EFF(m));
}
boolean isSymmetric(Matrix m){
/* Mengirimkan true jika m adalah matriks simetri : isSquare(m) 
   dan untuk setiap elemen m, m(i,j)=m(j,i) */
    if (!isSquare(m)){
        return false;
    } else {
        int i, j;
        for (i = 0; i < ROW_EFF(m); i++){
            for (j = 0; j < COL_EFF(m); j++){
                if (ELMT(m, i, j) != ELMT(m, j, i)){
                    return false;
                }
            }
        }
        return true;
    }
}
boolean isIdentity(Matrix m){
/* Mengirimkan true jika m adalah matriks satuan: isSquare(m) dan 
   setiap elemen diagonal m bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
    int i, j;
    if (!isSquare(m)){
        return false;
    } else {
        for (i = 0; i < ROW_EFF(m); i++){
            for (j = 0; j < COL_EFF(m); j++){
                if (i == j){
                    if (ELMT(m, i, j) != 1){
                        return false;
                    } 
                } else {
                    if (ELMT(m, i, j) != 0){
                        return false;
                    }
                }
            }
        }
        return true;
    }
}
boolean isSparse(Matrix m){
/* Mengirimkan true jika m adalah matriks sparse: matriks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
    int i, j, count;
    count = 0;
    for (i = 0; i < ROW_EFF(m); i++){
        for (j = 0; j < COL_EFF(m); j++){
            if (ELMT(m, i, j) != 0){
                count++;
            }
        }
    }
    return (((float)count/countElmt(m)) <= 0.05);
}
Matrix negation(Matrix m){
/* Menghasilkan salinan m dengan setiap elemen dinegasikan (dikalikan -1) */
    int i, j;
    Matrix m3;
    createMatrix(ROW_EFF(m), COL_EFF(m), &m3);
    for (i = 0; i < ROW_EFF(m); i++){
        for (j = 0; j < COL_EFF(m); j++){
            ELMT(m3, i, j) = ELMT(m, i, j) * (-1);
        }
    }
    return m3;
    //return (multiplyByConst(m, -1));
}
void pNegation(Matrix *m){
/* I.S. m terdefinisi */
/* F.S. m di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
    int i, j;
    for (i = 0; i < ROW_EFF(*m); i++){
        for (j = 0; j < COL_EFF(*m); j++){
            ELMT(*m, i, j) *= (-1);
        }
    }
    //pMultiplyByConst(m, -1);
}
float determinant(Matrix m) {
    /* Prekondisi: isSquare(m) */
    /* Menghitung nilai determinan m */
    int i, j, k, idx, temp1, temp2, det, cof;
    if (!isSquare(m)){
        return 0;
    }
    float *temp_row = (float *)malloc(ROW_EFF(m) * sizeof(float));
    det = 1.0;
    cof = 1.0;
    for(i = 0; i < ROW_EFF(m); i++){
        idx = i;
        while(ELMT(m, idx, i) == 0 && idx < ROW_EFF(m)){
            idx++;
        }
        if (idx == ROW_EFF(m)){
            free(temp_row);
            return 0;
        }
        if (i != idx){
            for(j = 0; j < ROW_EFF(m); j++){
                temp1 = ELMT(m,i,j);
                ELMT(m, i, j) = ELMT(m, idx, j);
                ELMT(m, idx, j) = temp1;
            }
            det *= -1;
        }
        for(j = 0; j<ROW_EFF(m) ;j++){
            temp_row[j] = ELMT(m, i, j);
        }
        for (j = i+1; j < ROW_EFF(m); j++){
            temp1 = temp_row[i];
            temp2 = ELMT(m, j, i);
            for(k = 0; k < ROW_EFF(m); k++){
                ELMT(m,j,k) = ((temp1 * ELMT(m,j,k)) - (temp2 * temp_row[k]));
            }
            cof *= temp1;
        }
    }
    for (i=0; i<ROW_EFF(m); i++){
        det *= ELMT(m, i, i);
    }
    free(temp_row);
    return (det/cof);
}

Matrix transpose(Matrix m){
/* I.S. m terdefinisi dan IsSquare(m) */
/* F.S. menghasilkan salinan transpose dari m, yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */
    Matrix m_t;
    int i, j;
    createMatrix(COL_EFF(m), ROW_EFF(m), &m_t);
    for (i = 0; i < ROW_EFF(m_t); i++){
        for (j = 0; j < COL_EFF(m_t); j++){
            ELMT(m_t, i, j) = ELMT(m, j, i);
        }
    }
    return m_t;
}
void pTranspose(Matrix *m){
/* I.S. m terdefinisi dan IsSquare(m) */
/* F.S. m "di-transpose", yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */
    ElType temp;
    int i, j;
    if (isSquare(*m)){
        for (i = 0; i < ROW_EFF(*m); i++){
            for (j = i + 1; j < COL_EFF(*m); j++){
                temp = ELMT(*m, i, j);
                ELMT(*m, i, j) = ELMT(*m, j, i);
                ELMT(*m, j, i) = temp;
            }
        }
    }
}

/*
#include "matrix.h"
#include <stdio.h>

int main(){
    Matrix m1, m2, m_op, m_copy;
    int row, col, i, j, cons;

    printf("rows: ");
    scanf("%d", &row);
    printf("cols: ");
    scanf("%d", &col);
    readMatrix(&m1, row, col);
    displayMatrix(m1);
    printf("elmt amt: %d\n", countElmt(m1));
    
    printf("last idx row: %d\n", getLastIdxRow(m1));
    printf("last idx col: %d\n", getLastIdxCol(m1));
    printf("idx to check: ");
    scanf("%d %d", &i, &j);
    if (isMatrixIdxValid(i, j)){
        printf("index dalam capacity\n");
    } else {
        printf("index di luar capacity\n");
    }
    if (isIdxEff(m1, i, j)){
        printf("index efektif\n");
    } else {
        printf("index tidak efektif\n");
    }

    if (isSquare(m1)){
        printf("square\n");
    } else {
        printf("not square\n");
    }
    if (isSymmetric(m1)){
        printf("symmetric\n");
    } else {
        printf("unsymmetric\n");
    }
    if (isIdentity(m1)){
        printf("identity\n");
    } else {
        printf("not identity\n");
    }
    if (isSparse(m1)){
        printf("sparse\n");
    } else {
        printf("not sparse\n");
    }

    printf("elmt(%d, %d): %d\n", i, i, getElmtDiagonal(m1, i));
    printf("det m1 = %.2f\n", determinant(m1));

    copyMatrix(m1, &m_copy);
    printf("copy dari m1:\n");
    displayMatrix(m_copy);
    m_op = negation(m1);
    printf("negation m1:\n");
    displayMatrix(m_op);
    pNegation(&m1);
    printf("m1:\n");
    displayMatrix(m1);
    m_op = transpose(m1);
    printf("transpose m1:\n");
    displayMatrix(m_op);
    pTranspose(&m1);
    printf("m1:\n");
    displayMatrix(m1); 


    printf("rows: ");
    scanf("%d", &row);
    printf("cols: ");
    scanf("%d", &col);
    readMatrix(&m2, row, col);
    displayMatrix(m2);

    if (isMatrixSizeEqual(m1, m2)){
        printf("size equal\n");
    } else {
        printf("size not equal\n");
    }
    if (isMatrixEqual(m1, m2)){
        printf("matrix equal\n");
    } 
    if (isMatrixNotEqual(m1, m2)) {
        printf("matrix not equal\n");
    }

    m_op = addMatrix(m1, m2);
    printf("m1 + m2 =\n");
    displayMatrix(m_op);
    m_op = subtractMatrix(m1, m2);
    printf("m1 - m2 =\n");
    displayMatrix(m_op);
    m_op = multiplyMatrix(m1, m2);
    printf("m1 * m2 =\n");
    displayMatrix(m_op);
    printf("const: ");
    scanf("%d", &cons);   
    m_op = multiplyByConst(m1, cons);
    printf("m1 * const =\n");
    displayMatrix(m_op);
    pMultiplyByConst(&m1, cons);
    printf("m1 =\n");
    displayMatrix(m1);

    return 0;
}
*/

// wrong in tc 60, 73-75