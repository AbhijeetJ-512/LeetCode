#include <vector>
using namespace std;
class Solution {
public:
  int minimumSubarrayLength(vector<int> &nums, int k) {
    int n = nums.size();
    int cnt[32] = {0};
    int ans = n + 1;
    int s = 0;

    for (int i = 0, j = 0; j < n; ++j) {
      s |= nums[j];
      for (int h = 0; h < 32; ++h) {
        if ((nums[j] >> h) & 1) {
          ++cnt[h];
        }
      }
      while (s >= k && i <= j) {
        ans = min(ans, j - i + 1);

        for (int h = 0; h < 32; ++h) {
          if ((nums[i] >> h) & 1) {
            if (--cnt[h] == 0) {
              s ^= (1 << h);
            }
          }
        }
        ++i;
      }
    }

    return ans > n ? -1 : ans;
  }
};
