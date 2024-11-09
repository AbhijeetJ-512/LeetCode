class Solution {
public:
  long long minEnd(int n, int x) {
    if (n == 1)
      return x;
    long long mask = x;
    long long last = n - 1;
    int leftmost = 0;

    for (long long i = 0; i < 64; i++) {
      if (((1LL << i) & last)) {
        leftmost = i;
      }
    }
    long long copy_bit = 0;
    for (long long i = 0; i < 64; ++i) {
      if ((mask & (1LL << i)) == 0) {
        if ((last & (1LL << copy_bit))) {
          mask |= (1LL << i);
        }
        copy_bit++;
        if (copy_bit == leftmost + 1) {
          break;
        }
      }
    }
    return mask;
  }
};
