// https://codeforces.com/gym/104339/problem/E
// Failed Solve, couldnt get it <1000ms, used Claude


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char base64_chars[] = 
  "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

unsigned char hex_to_byte(const char* hex) {
  unsigned char result = 0;
  for (int i = 0; i < 2; i++) {
    result <<= 4;
    char c = hex[i];
    if (c >= '0' && c <= '9')
      result |= (c - '0');
    else if (c >= 'A' && c <= 'F')
      result |= (c - 'A' + 10);
    else if (c >= 'a' && c <= 'f')
      result |= (c - 'a' + 10);
  }
  return result;
}

int main() {
  int k;
  scanf("%d", &k);

  unsigned char* input = malloc(k);
  char* output = malloc(((k + 2) / 3) * 4 + 1);
  int out_idx = 0;

  for (int i = 0; i < k; i++) {
    char hex[3];
    scanf(" %2s", hex);
    input[i] = hex_to_byte(hex);
  }

  for (int in_idx = 0; in_idx < k; ) {
    unsigned int triple = 0;
    int remaining = k - in_idx;

    if (remaining >= 3) {
      triple = (input[in_idx] << 16) | 
               (input[in_idx + 1] << 8) | 
               input[in_idx + 2];
      output[out_idx++] = base64_chars[(triple >> 18) & 0x3F];
      output[out_idx++] = base64_chars[(triple >> 12) & 0x3F];
      output[out_idx++] = base64_chars[(triple >> 6) & 0x3F];
      output[out_idx++] = base64_chars[triple & 0x3F];
      in_idx += 3;
    } else {
      triple = input[in_idx] << 16;
      
      if (remaining > 1)
        triple |= (input[in_idx + 1] << 8);
      
      output[out_idx++] = base64_chars[(triple >> 18) & 0x3F];
      output[out_idx++] = base64_chars[(triple >> 12) & 0x3F];
      
      if (remaining > 1)
        output[out_idx++] = base64_chars[(triple >> 6) & 0x3F];
      else
        output[out_idx++] = '=';
      
      output[out_idx++] = '=';
      break;
    }
  }

  output[out_idx] = '\0';
  printf("%s\n", output);
  
  free(input);
  free(output);
  return 0;
}