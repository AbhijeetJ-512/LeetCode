#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
  int largestCombination(vector<int> &candidates) {
    vector<int> answer(32, 0);
    for (auto x : candidates) {
      for (int i = 0; i < 31; ++i) {
        answer[i] += x & 1;
        x >>= 1;
      }
    }
    return *max_element(answer.begin(), answer.end());
  }
};
