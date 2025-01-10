#include "bintree.h"

int get_max(int a , int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int mencurry(BinTree T) {
    int opt1, opt2;
    if (isTreeEmpty(T)) {
        return 0;
    } else if (isOneElmt(T)) {
        return ROOT(T);
    } else if (isUnerLeft(T)) {
        return get_max(ROOT(T) + mencurry(LEFT(LEFT(T))) + mencurry(RIGHT(LEFT(T))) , mencurry(LEFT(T)));
    } else if (isUnerRight(T)) {
        return get_max(ROOT(T) + mencurry(LEFT(RIGHT(T))) + mencurry(RIGHT(RIGHT(T))) , mencurry(RIGHT(T)));
    } else {
        opt1 = ROOT(T) + mencurry(LEFT(LEFT(T))) + mencurry(RIGHT(LEFT(T))) + mencurry(LEFT(RIGHT(T))) + mencurry(RIGHT(RIGHT(T)));
        opt2 = mencurry(LEFT(T)) + mencurry(RIGHT(T));
        return get_max(opt1, opt2);
    }
}