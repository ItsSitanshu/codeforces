// https://codeforces.com/gym/104339/problem/B
// 21:05 Solve

#include <stdio.h>

int main() {
  int p1, p2, p3, p4;
  scanf("%d %d %d %d", &p1, &p2, &p3, &p4);

  if (p1 + p2 == p3 + p4 || 
    p1 + p3 == p2 + p4 || 
    p1 + p4 == p2 + p3 || 
    p1 == p2 + p3 + p4 || 
    p2 == p1 + p3 + p4 || 
    p3 == p1 + p2 + p4 || 
    p4 == p1 + p2 + p3) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }
  
  return 0;
}
