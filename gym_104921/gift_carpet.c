// https://codeforces.com/gym/104921/problem/D
// 48:45 Solve

#include <stdio.h>

int main() {
  int t;
  scanf("%d", &t);

  char sequence[4] = { 'v', 'i', 'k', 'a' };

  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);

    char carpet[n][m];

    for (int i = 0; i < n; i++) {
      scanf("%s", carpet[i]); 
    }

    int seq_index = 0;

    for (int j = 0; j < m && seq_index < 4; j++) { 
      for (int i = 0; i < n; i++) { 
        if (carpet[i][j] == sequence[seq_index]) {
          seq_index++; 
          break; 
        }
      }
    }

    if (seq_index == 4) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }

  return 0;
}
