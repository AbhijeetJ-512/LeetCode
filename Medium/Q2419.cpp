#include<vector>
using namespace std;
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int max = 0;
        for (auto x : nums) {
            if (max < x) {
                max = x;
            }
        }
        int currlength = 0, maxlength = 0;
        for (auto x : nums) {
            if (x == max) {
                currlength++;
                maxlength = (maxlength < currlength) ? currlength : maxlength;
            } else {
                currlength = 0;
            }
        }
        return maxlength;
    }
};
