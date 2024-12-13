#include <stdio.h>
#include <stdlib.h>
#include "list_circular.h"

int main (){
  List l;
  int N, i, val, min;
  Address p, prev, addr_min;
  boolean sorted;

  CreateList(&l);
  scanf("%d", &N);
  for (i = 0; i < N; i++){
    scanf("%d", &val);
    insertLast(&l, val);
  }

  sorted = true;
  p = FIRST(l);
  if (N == 1){ // 1 el
    //sorted = true;
  } else {
    p = FIRST(l);
    min = INFO(p);
    while (NEXT(p) != FIRST(l)){
      p = NEXT(p);
      if (INFO(p) > min){
        min = INFO(p);
      }
    }
    addr_min = search(l, min);
    p = addr_min;
    prev = p;
    p = NEXT(p);
    while (p != addr_min && sorted){
      prev = p;
      p = NEXT(p);
      if (INFO(p) < INFO (prev)){
        sorted = false;
      }
    }
    if (!sorted){
      sorted = true;
      p = addr_min;
      prev = p;
      p = NEXT(p);
      while (p != addr_min && sorted){
        if (INFO(p) > INFO (prev) && prev != addr_min){
          sorted = false;
        }
        prev = p;
        p = NEXT(p);
      }
    }
  }
  if (sorted){
    printf("YES\n");
  } else {
    printf("NO\n");
  }
  return 0;
}