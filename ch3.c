#import <stdio.h>

#define MAXLINE 1000

// 3-3
void expand(char s1[], char s2[]);
int isNumber(char c);
int isLetter(char c);
void insertRange(char start, char end, char str[], int *index);
int getChars(char str[]);

// 3-4
void itoa(int n, char s[]);
void reverse(char s[]);
int strLen(char s[]);

// 3-5
void itob(int n, char s[], unsigned b);

// 3-6
void itoaMinField(int n, char s[], unsigned m);

int main() {
  char s1[MAXLINE];
  char s2[MAXLINE];

  // getChars(s1);
  // expand(s1, s2);
  // printf("%s\n", s2);

  // itoa(-2147483648, s1);
  // printf("%s\n", s1);

  // itob(-16, s1, 2);
  // printf("%s\n", s1);

  itoaMinField(-2147483648, s1, 40);
  printf("%s\n", s1);

}

int getChars(char str[]) {
  char c;
  int i;

  for(i = 0; (c = getchar()) != EOF && c != '\n'; i++) {
    str[i] = c;
  }

  str[i] = '\0';

  return i;
}

void expand(char s1[], char s2[]) {
  int i = 0, j = 0;
  char c;
  // check for leading - and add it to s2
  if (s1[i] == '-') {
    i++;
  }

  while ((c = s1[i]) != '\0') {
    if (c == '-') {
      char prev = s1[i-1];
      char next = s1[i+1];
      if (isLetter(prev)) {
        if (isLetter(next)) {
          insertRange(prev+1, next, s2, &j);
          i += 2;
        } else {
          i += 2;
        }
      } else {
        if (isNumber(prev)) {
          if (isNumber(next)) {
            insertRange(prev+1, next, s2, &j);
            i += 2;
          } else {
            i += 2;
          }
        } else {
          i++;
        }
      }
    } else {
      printf("%d %d \n", j, c);
      s2[j++] = c;
      i++;
    }
  }
}

int isNumber(char c) {
  return c >= '0' && c <= '9';
}

int isLetter(char c) {
  return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

void insertRange(char start, char end, char str[], int *index) {
  while (start <= end) {
    str[*index] = start;
    start++;
    (*index)++;
  }
}

// 3-4
void itoa(int n, char s[]) {
  int isMostNegative = 0;
  int i = 0;

  // check if most negative number
  if (n == ~n + 1) {
    isMostNegative = 1;
    n = n + 1;
  }

  int isNegative = n < 0;

  // convert to positive
  if (isNegative) {
    n = -n;
  }

  // successively get remainder in division by ten and add to string
  do {
    s[i] = '0' + (n % 10) + (i == 0 && isMostNegative ? 1 : 0);
    i++;
  } while ((n /= 10) > 0);
  if (isNegative) {
    s[i++] = '-';
  }
  s[i] = '\0';
  reverse(s);
}

// 3-5
void itob(int n, char s[], unsigned b) {
  int isNegative = n < 0;
  int i, r, rem;

  if (isNegative) {
    n = -n;
  }

  do {
    s[i++] = '0' + (n % b);
  } while ((n /= b) != 0);

  if (isNegative) {
    s[i] = '-';
  }

  reverse(s);
}

// 3-6
void itoaMinField(int n, char s[], unsigned m) {
  int isMostNegative = 0;
  int i = 0;

  // check if most negative number
  if (n == ~n + 1) {
    isMostNegative = 1;
    n = n + 1;
  }

  int isNegative = n < 0;

  // convert to positive
  if (isNegative) {
    n = -n;
  }

  // successively get remainder in division by ten and add to string
  do {
    s[i] = '0' + (n % 10) + (i == 0 && isMostNegative ? 1 : 0);
    i++;
  } while ((n /= 10) > 0);

  if (i < m - 1) {
    for(; i < m; i++) {
      s[i] = '0';
    }
  }

  if (isNegative) {
    s[i++] = '-';
  }
  s[i] = '\0';
  reverse(s);
}

void reverse(char s[]) {
  int c, i = 0, j = strLen(s) - 1;

  while (i <= j) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
    i++; j--;
  }
}

int strLen(char s[]) {
  int i = 0;

  for(i = 0; s[i] != '\0'; i++) ;

  return i;
}
