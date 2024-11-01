#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  int smallestRangeII(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());
    size_t n = nums.size();
    int ans = nums[n - 1] - nums[0];
    for (size_t i = 0; i < n - 1; ++i) {
      int min_num = min(nums[0] + k, nums[i + 1] - k);
      int max_num = max(nums[i] + k, nums[n - 1] - k);
      ans = min(ans, max_num - min_num);
    }
    return ans;
  }
};
