#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
  int smallestRangeI(vector<int> &nums, int k) {
    int big = *max_element(nums.begin(), nums.end());
    int small = *min_element(nums.begin(), nums.end());
    return max(0, big - small - 2 * k);
  }
};
