// https://codeforces.com/gym/104921/problem/C
// 35:45 Solves

#include <stdio.h>
#include <string.h>

int main() {
  int t;
  scanf("%d", &t);

  while (t--) {
    char cases[8][8]; 
    char results[8];  

    for (int i = 0; i < 8; i++) {
      scanf("%s", cases[i]);
    }

    int l = 0;

    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        if (cases[i][j] != '.') {
          results[l++] = cases[i][j]; // Store non-dot characters
        }
      }
    }
    
    results[l] = '\0'; 

    printf("%s\n", results);
  }

  return 0;
}
