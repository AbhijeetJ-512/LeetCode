#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        vector<int> copy(nums);
        nums.clear();
        for (int i = 0; i < copy.size(); ++i)
        {
            if (copy[i] != val)
            {
                nums.push_back(copy[i]);
            }
        }
        vector<int>().swap(copy);
        return nums.size();
    }
};