#include <limits.h>

int reverse(int x) {
  int cpy = 0;
  while (x != 0) {
    if (cpy > INT_MAX / 10 || cpy < INT_MIN / 10) {
      return 0;
    }
    cpy = cpy * 10 + x % 10;
    x = x / 10;
  }
  return cpy;
}