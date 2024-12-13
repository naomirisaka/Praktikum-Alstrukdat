#include <stdio.h>
#include <stdlib.h>
#include "list_circular.h"

int main (){
  List l;
  int N, i, val, max;
  Address p;

  CreateList(&l);
  scanf("%d", &N);
  for (i = 0; i < N; i++){
    scanf("%d", &val);
    insertLast(&l, val);
  }

  p = FIRST(l);
  max = INFO(p);
  while (NEXT(p) != FIRST(l)){
    p = NEXT(p);
    if (INFO(p) > max){
      max = INFO(p);
    }
  }

  p = FIRST(l);
  while (INFO(p) != max){
    FIRST(l) = NEXT(FIRST(l));
    p = FIRST(l);
  }
  
  displayList(l);

  return 0;
}