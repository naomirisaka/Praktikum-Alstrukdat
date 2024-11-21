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