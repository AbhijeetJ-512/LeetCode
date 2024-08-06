#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int current = INT_MAX;
        int closestSum = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.size() - 2; ++i)
        {
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right)
            {
                current = nums[i] + nums[left] + nums[right];
                if (std::abs(current - target) < std::abs(closestSum - target))
                {
                    closestSum = current;
                }
                if (current < target)
                {
                    ++left;
                }
                else if (current > target)
                {
                    --right;
                }
                else
                {
                    return closestSum;
                }
            }
        }
        return closestSum;
    }
};