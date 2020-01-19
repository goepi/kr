#include <stdio.h>

void incrementPointer(int *p) {

}

void test(int *p) {
  printf(p);
}

int main() {
  const int ARRAY_SIZE = 10;
  int *p;
  int x = 3;
  p = &x;
  printf("p star is %d\n", *p);
  test(p);
}
