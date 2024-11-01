using namespace std;
class Solution {
public:
  int findKthNumber(int n, int k) {
    long cur = 1;
    --k;
    while (k > 0) {
      long steps = countSteps(n, cur, cur + 1);
      if (steps <= k) {
        cur += 1;
        k -= steps;
      } else {
        cur *= 10;
        --k;
      }
    }
    return cur;
  }
  long countSteps(int n, long cur, long next) {
    long steps = 0;
    while (cur <= n) {
      steps += min(next, (long)n + 1) - cur;
      cur *= 10;
      next *= 10;
    }
    return steps;
  }
};
