// https://codeforces.com/gym/104339/problem/A
// 8:50 Solve

#include "stdio.h"

int main () {
  int x, y, z, a, b, c;
  scanf("%d %d %d %d %d %d", &a, &b, &c, &x, &y, &z);

  int kings[] = {x * a, y * b, z * c};
  char* kings_names[] = {"Barley", "Hops", "Malt"};
  int max = 0;


  for (int i = 0; i < 3; i++) {
    if (max < kings[i]) {
      max = kings[i];
    }
  }

  for (int i = 0; i < 3; i++) {
    if (max == kings[i]) {
      printf("%s ", kings_names[i]);
    }
  }

  printf("\n");

  return 0;
}