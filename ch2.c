#include <stdio.h>

// 2-3
int htoi(char[]);
int hexDigitToInt(char);

// 2-4
void squeeze(char[], int);

// 2-5
int any(char[], char[]);

// 2-6
int setBits(unsigned x, unsigned p, unsigned n, unsigned y);

// 2-7
int invertBits(unsigned x, unsigned p, unsigned n);

// 2-8
int rightRot(unsigned x, unsigned n);

// 2-9
int bitCount(unsigned x);

// 2-10
void lower(char str[]);

int main() {
  int result = htoi("FF");
  printf("Result is %d\n", result);

  char str[] = "Hello jello";
  squeeze(str, 'l');
  printf("Str result is %s\n", str);

  int resultAny = any("hello", "yumel");
  printf("Any result is %d\n", resultAny);

  int setBitsResult = setBits(170, 5, 3, 234);
  printf("setBits %d\n", setBitsResult);

  int invertBitsResult = invertBits(128, 7, 8);
  printf("invertBits %d\n", invertBitsResult);

  int rr = rightRot(011, 3);
  printf("rotate right %d\n", rr);

  int bc = bitCount(033);
  printf("bit count %d\n", bc);

  char s[] = "HELLO there YOU.";
  printf("Original is: %s\n", s);
  lower(s);
  printf("Lower is: %s\n", s);
}

int htoi(char str[]) {
  int i = 0, sum = 0;
  char c;
  // check if the string starts with optional 0x or 0X
  if (str[0] == '0' && (str[1] == 'X' || str[1] == 'x')) {
    i = 2;
  }

  // iterate through the string and sum
  while ((c = str[i]) != '\0') {
    int integer = hexDigitToInt(c);
    if (integer == -1) {
      return -1;
    }
    sum = sum*16 + integer;
    i++;
  }

  return sum;
}

int hexDigitToInt(char hexDigit) {
  if (hexDigit >= '0' && hexDigit <= '9') {
    return hexDigit - '0';
  } else if (hexDigit >= 'A' && hexDigit <= 'F') {
    return hexDigit - 'A' + 10;
  } else if (hexDigit >= 'a' && hexDigit <= 'f') {
    return hexDigit - 'a' + 10;
  }
  return -1;
}

void squeeze(char str[], int c) {
  int i = 0, j = 0;

  while (str[i] != '\0') {
    if (str[i] == c) {
      str[j++] = str[i];
    }
    i++;
  }
  str[j] = '\0';
}

int any(char s1[], char s2[]) {
  int i, j;
  char c2;

  for(i = 0; (c2 = s2[i]) != '\0'; i++) {
    for(j = 0; s1[j] != '\0'; j++) {
      if (s1[j] == c2) {
        return j;
      }
    }
  }
  return -1;
}

// example x is 10101010
// y is 11101010
// p is 5, n is 3
int setBits(unsigned x, unsigned p, unsigned n, unsigned y) {
  int rightMask = ~(~0 << n);  // 00000111
  int midMask = ~(rightMask << (p + 1 - n));  // 11000111
  int yMask = ((rightMask & y) << n) | midMask;  // 11010111

  return yMask & (x | ~midMask);  // 10010010
}

int invertBits(unsigned x, unsigned p, unsigned n) {
  int rightMask = ~(~0 << n);  // 00000111
  int midOnMask = rightMask << (p + 1 - n);  // 00111000
  int midOffMask = ~midOnMask;  // 11000111

  int midInverted = (midOnMask & ~x) | midOffMask;  // 11010111

  return midInverted & (x | midOnMask); // 10010010
}

int rightRot(unsigned x, unsigned n) {
  int size = sizeof(unsigned);
  int bits = size*8;

  int right = x >> n;
  int left = x << (bits-n);

  return left | right;
}

int bitCount(unsigned x) {
  unsigned int b;
  for(b = 0; x != 0; x &= (x-1)) {
    b++;
  }

  return b;
}

void lower(char str[]) {
  int i;
  while ((str[i] = (str[i] > 'A' && str[i] < 'Z' ? 'a' + str[i] - 'A' : str[i])) != '\0') { i++; }
}
