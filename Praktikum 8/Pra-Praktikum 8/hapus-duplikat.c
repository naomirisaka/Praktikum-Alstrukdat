#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"
#include "boolean.h"

List hapusDuplikat(List l){
/**
 * Menerima masukan sebuah list l yang terurut mengecil
 * Mengembalikan list yang merupakan hasil penghapusan elemen yang mempunyai duplikat pada list l, terurut membesar
 * Contoh: hapusDuplikat(3->3->2->1) = 1->2 (-> adalah panah next pada list linear)
 */
    List l_result;
    Address p, p_move;
    boolean has_dup, has_moredup;

    CreateList(&l_result);
    p = FIRST(l);
    while (p != NULL) {
        p_move = NEXT(p);
        has_dup = false;
        while (p_move != NULL) {
            if (INFO(p_move) == INFO(p)) {
                has_dup = true;
                break;
            }
            p_move = NEXT(p_move);
        }

        if (!has_dup) {
            p_move = FIRST(l);
            has_moredup = false;
            while (p_move != p) {  // check before p
                if (INFO(p_move) == INFO(p)) {
                    has_moredup = true;
                    break;
                }
                p_move = NEXT(p_move);
            }
            if (!has_moredup) {
                insertFirst(&l_result, INFO(p));
            }
        }

        p = NEXT(p);
    }
    return l_result;
}

/*
int main() {
    List l, l_new;
    int n, val;
    CreateList(&l);
    CreateList(&l_new);

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        insertLast(&l, val);
    }
    displayList(l);
    l_new = hapusDuplikat(l);
    displayList(l_new);
    return 0;
}
*/