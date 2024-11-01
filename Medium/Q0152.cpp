#include<vector>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            int currprod = 1;

            for (int j = i; j < nums.size(); j++) {
                currprod = currprod * nums[j];
                res = max(res, currprod);
            }
        }
        return res;
    }
};
