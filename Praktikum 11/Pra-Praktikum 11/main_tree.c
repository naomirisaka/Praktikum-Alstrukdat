#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"
#include "boolean.h"

int main(){
    BinTree T, T_left, T_right;
    int val;

    printf("Left child: ");
    scanf("%d", &val);
    T_left = NewTree(val, NULL, NULL);
    if (isTreeEmpty(T_right)){
        printf("Right child is empty\n");
    }
    printf("Right child: ");
    scanf("%d", &val);
    T_right = NewTree(val, NULL, NULL);
    if (isOneElmt(T_right)){
        printf("Right child is leaf\n");
    } 
    printf("Root: ");
    scanf("%d", &val);
    CreateTree(val, T_left, T_right, &T);
    if (isBinary(T)){
        printf("This is a binary tree\n");
    } else if (isUnerLeft(T)){
        printf("This is a left-leaning tree\n");
    } else if (isUnerRight(T)){
        printf("This is a right-leaning tree\n");
    }

    printf("Preorder: ");
    printPreorder(T);
    printf("\n");
    printf("Inorder: ");
    printInorder(T);
    printf("\n");
    printf("Postorder: "); 
    printPostorder(T);
    printf("\n");
    printf("Tree:\n");
    printTree(T, 2);

    return 0;
}