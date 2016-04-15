#include <stdio.h>
#include <stdlib.h>
#include "shittycode.h"

struct data1 {
  int a;
  char *name;
};

struct data2 {
  float a;
  double b;
};

struct data1 d1[3];
struct data2 d2[3];

void makeModel1(){
  int i = 0;
  for(i = 0; i < 3; i++) {
    d1[i].a = i + 1;
    d1[i].name = "Code Ninja";
  }
}

void makeModel2(){
  int i = 0;
  for(i = 0; i < 3; i++) {
    d2[i].a = i + 2;
    d2[i].b = i * 0.235;
  }
}

int main() {
  LIST(l1); // generic data type list.
  LIST(l2);
  makeModel1(); // demo model... model can come from anywhere
  makeModel2(); // demo model... model can be any thing
  l1.constructor((char *)&d1, &l1); // must send a reference to self
  l2.constructor((char *)&d2, &l2);
  struct data1 *r1 = (struct data1 *)l1.getter(&l1);
  printf("%s, %d\n", r1[2].name, r1[1].a);
  struct data2 *r2 = (struct data2 *)l2.getter(&l2);
  printf("%f, %f\n", r2[2].b, r2[1].a);
  return 0;
}
