#include "listrec.h"
#include <stdio.h>
#include <stdlib.h>

void mergeSortedUnique(List l1, List l2, List *res) {
  if (isEmpty(l1) && isEmpty(l2)) {
    // do nothing
  } else if (isEmpty(l1) && !isEmpty(l2)) {
    if (!isMember(*res, head(l2))) {
      *res = konsb(*res, head(l2)); 
    }
    mergeSortedUnique(l1, tail(l2), res); 
  } else if (!isEmpty(l1) && isEmpty(l2)) {
      if (!isMember(*res, head(l1))) {
        *res = konsb(*res, head(l1)); 
      }
      mergeSortedUnique(tail(l1), l2, res); 
  } else { // both ga kosong
    if (head(l1) < head(l2)) {
      if (!isMember(*res, head(l1))) {
          *res = konsb(*res, head(l1)); 
      }
      mergeSortedUnique(tail(l1), l2, res); 
    } else if (head(l1) > head(l2)) {
      if (!isMember(*res, head(l2))) {
          *res = konsb(*res, head(l2));
      }
      mergeSortedUnique(l1, tail(l2), res); 
    } else { // both head sama
      if (!isMember(*res, head(l1))) {
          *res = konsb(*res, head(l1)); 
      }
      mergeSortedUnique(tail(l1), tail(l2), res);
    }
  }
}

/*
int main(){
    List l1 = NULL, l2 = NULL; 
    int n, i, val;

    printf("List 1\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        scanf("%d", &val);
        l1 = konsb(l1, val);
    }
    displayList(l1);

    printf("List 2\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        scanf("%d", &val);
        l2 = konsb(l2, val);
    }
    displayList(l2);
    printf("Merged sorted list:\n");

    List res = NULL;
    mergeSortedUnique(l1, l2, &res);
    displayList(res);
    
    return 0;
} 
*/