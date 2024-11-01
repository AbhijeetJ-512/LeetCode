#include <cstdlib>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
  bool containsNearbyDuplicate(vector<int> &nums, int k) {
    unordered_map<int, int> my_map;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      if (my_map.count(nums[i])) {
        if (abs(i - my_map[nums[i]]) <= k) {
          return true;
        }
      }
      my_map[nums[i]] = i;
    }
    return false;
  }
};
