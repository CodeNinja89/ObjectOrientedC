#include <stdio.h>
#include <stdlib.h>
#include "shittycode.h"

struct data1 {
  int a;
  char *name;
};

struct data1 d1[3];

void makeModel1(){
  int i = 0;
  for(i = 0; i < 3; i++) {
    d1[i].a = i + 1;
    d1[i].name = "Code Ninja";
  }
}

void callback(LIST listObject) { // callback function to parse and do things with the list elements.
  int count = 0;
  struct data1 *r1 = (struct data1 *)listObject.getter(&listObject);
  for(count = 0; count < 3; count++) {
    printf("%s, %d\n", r1[count].name, r1[count].a);
  }
}

int main() {
  LIST(l1); // generic data type list.
  makeModel1(); // demo model...
  l1.constructor((char *)&d1, &l1, &callback); // must send a reference to self
  l1.iterator(l1);
  return 0;
}
