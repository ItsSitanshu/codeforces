// https://codeforces.com/gym/104921/problem/B 
// 72:06 Solve

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main() {
  int t;
  scanf("%d", &t);
  
  while (t--) {
    int n, n2, n3;
    int prod, prod2;
    scanf("%d", &n);

    int nums[n];

    for (int i = 0; i < n; i++) {
      scanf("%d", &nums[i]);
    }

    n2 = n;
    prod = 1;
    prod2 = 0;

    while (n2--) {
      n3 = n;
      prod = 1;

      while (n3--) {
        prod = prod * (n3 == n2 ? (nums[n3] + 1) : nums[n3]);
        // printf("prod(%d) >= prod2(%d) is %d; [ %d ]\n", prod, prod2, prod >= prod2, n);
      }
      prod2 = prod >= prod2 ? prod : prod2;
    }

    printf("%d\n", prod2);
  }


  return 0;
}
