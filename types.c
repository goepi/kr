#include <limits.h>
#include <float.h>
#include <stdio.h>

void shortIntTest(void);
void longIntTest(void);
void floatTest(void);

int main() {
  shortIntTest();
  longIntTest();
  // floatTest();
  return 1;
}

void shortIntTest() {
  int i = 1;
  short unsigned int test = 1;
  printf("%5s %s\n", "bits", "value");
  while (test != 0) {
    printf("%5u %u\n", i, test);
    test = test*2;
    i++;
  }
  printf("Max bits for short int is %d\n", i-1);
}

void longIntTest() {
  int i = 1;
  long unsigned int test = 1;
  printf("%5s %s\n", "bits", "value");
  while (test != 0) {
    printf("%5u %lu\n", i, test);
    test = test*2;
    i++;
  }
  printf("Max bits for long int is %d\n", i-1);
}

// this is incorrect, value of test becomes Inf, not zero
void floatTest() {
  int i = 1;
  float test = 1;
  printf("%5s %s\n", "bits", "value");
  while (test != 0) {
    printf("%5u %f\n", i, test);
    test = test*2;
    i++;
  }
  printf("Max bits for float is %d\n", i-1);
}
