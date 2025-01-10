#include <stdio.h>
#include "bintree.h"

void invertTree(BinTree *p) {
  if (isTreeEmpty(*p)){
    // do nothing
  } else if (isOneElmt(*p)){
    // do nothing as well
  } else if (isUnerLeft(*p)){
    RIGHT(*p) = LEFT(*p);
    LEFT(*p) = NULL;
    invertTree(&RIGHT(*p)); 
  } else if (isUnerRight(*p)){
    LEFT(*p) = RIGHT(*p);
    RIGHT(*p) = NULL;
    invertTree(&LEFT(*p)); 
  } else {
    BinTree temp; 
    temp = LEFT(*p);
    LEFT(*p) = RIGHT(*p);
    RIGHT(*p) = temp;
    invertTree(&LEFT(*p));
    invertTree(&RIGHT(*p));
  }
}