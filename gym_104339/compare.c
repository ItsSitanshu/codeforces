// https://codeforces.com/gym/104339/problem/E
// 20:09 + 15:45 Solve

#include "stdio.h"
#include "string.h"

// Trims leading zeros from a string
void trim(char* str) {
  int i = 0;

  while (str[i] == '0') {
    i++;
  }

  if (str[i] == '\0') {
    str[0] = '\0'; 
    return;
  }

  if (i > 0) {
    int j = 0;
    while (str[i] != '\0') {
      str[j++] = str[i++];
    }
    str[j] = '\0';
  }
}

void parse_input(const char* input, char* integer_part, char* fractional_part) {
  integer_part[0] = '0'; 
  integer_part[1] = '\0';
  fractional_part[0] = '\0';

  char* dot_position = strchr(input, '.');
  if (dot_position != NULL) {
    *dot_position = '\0'; 
    if (dot_position != input) {
      strcpy(integer_part, input); 
    }
    strcpy(fractional_part, dot_position + 1); 
  } else {
    strcpy(integer_part, input);
  }
}


int main() {
  int MAX = 100000;
  char n1[MAX], n2[MAX], f1[MAX], f2[MAX];
  char str1[MAX * 2 + 2], str2[MAX * 2 + 2];

  scanf("%s", str1);
  scanf("%s", str2);

  f1[0] = f2[0] = '\0';
  n1[0] = n2[0] = '0'; n1[1] = n2[1] = '\0';

  parse_input(str1, n1, f1);
  parse_input(str2, n2, f2);
  
  trim(n1);
  trim(n2);

  int ln1 = strlen(n1);
  int ln2 = strlen(n2);

  if (ln1 > ln2) {
    printf("1\n");
    return 0;
  }
  if (ln2 > ln1) {
    printf("-1\n");
    return 0;
  }

  for (int i = 0; i < ln1; i++) {
    if (n1[i] > n2[i]) {
      printf("1\n");
      return 0;
    }
    if (n2[i] > n1[i]) {
      printf("-1\n");
      return 0;
    }
  }

  int i = 0;
  while (f1[i] != '\0' || f2[i] != '\0') {
    char c1 = (f1[i] != '\0') ? f1[i] : '0'; 
    char c2 = (f2[i] != '\0') ? f2[i] : '0'; 

    if (c1 > c2) {
      printf("1\n");
      return 0;
    }
    if (c2 > c1) {
      printf("-1\n");
      return 0;
    }
    i++;
  }


  printf("0\n");
  return 0;
}
