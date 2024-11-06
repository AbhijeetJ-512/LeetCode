#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
  int countPrimes(int n) {
    vector<bool> answer(n + 1, true);
    for (int i = 2; i * i <= n; ++i) {
      if (answer[i] == true) {
        for (int j = i * i; j < n; j += i) {
          answer[j] = false;
        }
      }
    }
    return max(static_cast<int>(count(answer.begin(), answer.end(), true)) - 3,
               0);
  }
};
