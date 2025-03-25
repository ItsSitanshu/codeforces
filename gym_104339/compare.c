// https://codeforces.com/gym/104339/problem/E
// 20:09

#include "stdio.h"
#include "string.h"

int main() {
  int MAX = 100000;
  char n1[MAX], n2[MAX], f1[MAX], f2[MAX];
  char str1[MAX * 2 + 2], str2[MAX * 2 + 2];

  scanf("%s", str1);
  scanf("%s", str2);

  sscanf(str1, "%[^.].%s", n1, f1);
  sscanf(str2, "%[^.].%s", n2, f2);
  
  int ln1 = strlen(n1);
  int ln2 = strlen(n2);

  if (ln1 > ln2) return 1;
  if (ln2 > ln1) return -1;

  for (int i = 0; i < ln1; i++) {
    if (n1[i] > n2[i]) return 1;
    if (n2[i] > n1[i]) return -1;
  }

  int fn1 = strlen(f1);
  int fn2 = strlen(f2);

  if (fn1 > fn2) return 1;
  if (fn2 > fn1) return -1;

  for (int i = 0; i < fn1; i++) {
    if (f1[i] > f2[i]) return 1;
    if (f2[i] > f1[i]) return -1;
  }

  return 0;
}