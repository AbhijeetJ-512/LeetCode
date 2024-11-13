#include <vector>
using namespace std;
class Solution {
public:
  int count_b(int n) {
    int count = 0;
    while (n != 0) {
      count += n & 1;
      n >>= 1;
    }
    return count;
  }
  vector<int> countBits(int n) {
    vector<int> answer(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
      answer[i] = count_b(i);
    }
    return answer;
  }
};
