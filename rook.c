// https://codeforces.com/gym/104921/problem/A

#include <stdio.h>

int main() {
  int row, col;
  int t;

  scanf("%d", &t);
  for (int k = 1; k <= t; k++) {
    char testcase[3]; 
    scanf("%s", testcase); 

    char letters[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};

    row = testcase[0] - 'a' + 1;
    col = testcase[1] - '1' + 1;

    for (int i = 1; i <= 8; i++) {
      if (i != row)
      printf("%c%d\n", letters[i - 1], col);
    }

    for (int j = 1; j <= 8; j++) {
      if (j != col)
      printf("%c%d\n", letters[row - 1], j);
    }
  }

  return 0;
}
