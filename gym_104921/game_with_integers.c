// https://codeforces.com/gym/104921/problem/E
// 25:17 Solve

#include <stdio.h>

int main() {
  int t;
  scanf("%d", &t);

  while (t--) {
    int n, moves = 0;
    scanf("%d", &n);

    if (n % 3 == 0) {
      printf("Second\n");
    } else {
      while (moves < 10) {
        if ((n + 1) % 3 == 0 || (n - 1) % 3 == 0) {
          printf("First\n");
          break;
        }

        n += 1;
        moves++;
      }

      if (moves == 10) {
        printf("Second\n");
      }
    }

  }

  return 0;
}
