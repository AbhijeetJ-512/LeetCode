#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
  long long countFairPairs(vector<int> &nums, int lower, int upper) {
    sort(nums.begin(), nums.end());
    long long count = 0;
    int n = nums.size();
    for (int i = 0; i < n - 1; i++) {
      int x = lower - nums[i], y = upper - nums[i];
      auto it = lower_bound(nums.begin() + i + 1, nums.end(), x);
      auto gt = upper_bound(nums.begin() + i + 1, nums.end(), y);
      count += gt - it;
    }
    return count;
  }
};
