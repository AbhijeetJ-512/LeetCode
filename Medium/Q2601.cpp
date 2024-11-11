#include <vector>
using namespace std;
class Solution {
public:
  void algo(vector<bool> &prime, int n) {
    prime[0] = prime[1] = false;
    for (int i = 2; i * i < n; i++) {
      for (int j = i * 2; j < n; j += i) {
        prime[j] = false;
      }
    }
  }
  bool primeSubOperation(vector<int> &nums) {
    int n = nums.size();
    if (n < 2) {
      return true;
    }
    vector<bool> isprime(1001, true);
    algo(isprime, 1001);

    vector<int> prime;
    for (int i = 0; i < 1001; ++i) {
      if (isprime[i])
        prime.push_back(i);
    }
    bool flag = true;
    int prev = nums[n - 1];
    for (int i = n - 2; i >= 0; i--) {
      flag = true;
      if (nums[i] < prev) {
        prev = nums[i];
        flag = false;
        continue;
      }
      for (int sub = 0; sub < prime.size() && prime[sub] < nums[i]; sub++) {
        if (nums[i] - prime[sub] < prev) {
          prev = nums[i] - prime[sub];
          flag = false;
          break;
        }
      }
      if (flag)
        break;
    }
    return !flag;
  }
};
