#include<vector>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return nums[0];

        vector<int> profit(nums.size(), 0);
        profit[0] = nums[0];
        profit[1] = (nums[0] > nums[1]) ? nums[0] : nums[1];

        for (int i = 2; i < nums.size(); ++i) {
            profit[i] = (profit[i - 1] > profit[i - 2] + nums[i])
                            ? profit[i - 1]
                            : profit[i - 2] + nums[i];
        }

        return profit.back();
    }
};
