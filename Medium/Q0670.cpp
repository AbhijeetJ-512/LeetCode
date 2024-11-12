#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
  int maximumSwap(int num) {
    if (num == 0) {
      return num;
    }

    vector<int> digits;
    int temp = num;

    while (temp > 0) {
      digits.push_back(temp % 10);
      temp /= 10;
    }
    reverse(digits.begin(), digits.end());
    int n = digits.size();
    vector<int> last(10, -1);

    for (int i = 0; i < n; i++) {
      last[digits[i]] = i;
    }

    for (int i = 0; i < n; i++) {
      for (int d = 9; d > digits[i]; d--) {
        if (last[d] > i) {
          swap(digits[i], digits[last[d]]);
          int result = 0;
          for (int digit : digits) {
            result = result * 10 + digit;
          }
          return result;
        }
      }
    }

    return num;
  }
};
