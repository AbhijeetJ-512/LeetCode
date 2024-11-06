#include <vector>
using namespace std;
class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    vector<int> ans;
    long long int product = 1;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      product *= nums[i];
    }
    for (int i = 0; i < n; ++i) {
      if (nums[i] == 0) {
        ans.push_back(1);
        for (int j = 0; j < n; ++j) {
          if (i != j) {
            ans.back() *= nums[j];
          }
        }
      } else {
        ans.push_back(static_cast<int>(product / nums[i]));
      }
    }
    return ans;
  }
};
