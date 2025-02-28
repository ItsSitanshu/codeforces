// https://codeforces.com/gym/104921/problem/F
// 44:18 Solve

#include "stdio.h"
#include "stdlib.h"

int main() {
  int t, steps, i, cursor;
  scanf("%d", &t);

  while (t--) {
    char pin[5];
    steps = 0;
    i = 0;
    cursor = 1;

    scanf("%s", pin);
    
    int cur = pin[i] - '0';
    
    while (i <= 3) {
      
      if (cur == cursor) {
        i = i + 1;
        cur = pin[i] - '0';
      } else if (cursor > cur && cur != 0) {
        cursor -= 1;
      } else {
        if (cursor == 9) {
          cursor = 0;
        } else if (cursor == 0) {
          cursor = 9;
        } else {
          cursor += 1;
        }
      }

      steps += 1;
    }

    printf("%d\n", steps);
  }

  return 0;
}