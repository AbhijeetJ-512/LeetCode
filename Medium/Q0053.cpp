#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int ans = nums[0];
        int cur = 0;
        for (auto x : nums)
        {
            if (cur < 0)
            {
                cur = 0;
            }
            cur += x;
            ans = (ans > cur) ? ans : cur;
        }
        return ans;
    }
};