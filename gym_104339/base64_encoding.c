// https://codeforces.com/gym/104339/problem/D
// 45:05 Solve

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int hex_to_bin(const char *hex) {
  int num;
  sscanf(hex, "%x", &num); 
  return num & 0xFF;      
}

int main() {
  char map[65] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"; // Base64 alphabet
  int k;
  scanf("%d", &k);

  char concatenated_binary[1000] = "";
  for (int i = 0; i < k; i++) {
    char n[3] = {};
    scanf(" %2s", n);
  
    int bin_result = hex_to_bin(n);
    char bin_str[9];  
  
    for (int i = 7; i >= 0; i--) {
      bin_str[i] = (bin_result & 1) ? '1' : '0';
      bin_result >>= 1;
    }
    bin_str[8] = '\0';
    
    int len = strlen(bin_str);
    strcat(concatenated_binary, bin_str);
  }
  
  int bin_len = strlen(concatenated_binary);

  while (bin_len % 6 != 0) {
    strcat(concatenated_binary, "0");
    bin_len++;
  }

  int remainder = bin_len % 6;

  char base64_output[200] = ""; 
  for (int i = 0; i < bin_len; i += 6) {
    char chunk[7] = {0};
    strncpy(chunk, concatenated_binary + i, 6);
    int index = strtol(chunk, NULL, 2);
    strncat(base64_output, &map[index], 1);
  }

  int base64_len = strlen(base64_output);
  while (base64_len % 4 != 0) {
    strcat(base64_output, "=");
    base64_len++;
  }

  printf("%s\n", base64_output);
  return 0;
}
