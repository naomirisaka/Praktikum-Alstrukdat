#include "listrec.h"
#include <stdio.h>
#include <stdlib.h>

ElType getLast(List l){
  if (isEmpty(tail(l))){
      return head(l);
  } else {
      return (getLast(tail(l)));
  }
}

List sortList(List l, List res){
  if (isEmpty(l)){
    displayList(res);
  } else {
    res = konsb(res, head(l));
    l = deleteFirst(l);
    if (!isEmpty(l)){
      res = konsb(res, getLast(l));
      l = deleteLast(l);
    }
    sortList(l, res);
  }
}

int main(){
  List l = NULL, res = NULL;
  int n, i, val;
  scanf("%d", &n);
  for (i = 0; i < n; i++){
    scanf("%d", &val);
    l = konsb(l, val);
  }
  sortList(l, res);
  return 0;
}