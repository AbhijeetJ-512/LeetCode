#include <algorithm>
#include <climits>
#include <vector>
using namespace std;
class Solution {
public:
  vector<int> maximumBeauty(vector<vector<int>> &items, vector<int> &queries) {
    vector<vector<int>> res = {{0, 0, INT_MAX}};
    sort(items.begin(), items.end());

    for (auto item : items) {
      int p = item[0];
      int b = item[1];
      if (b > res.back()[1]) {
        res.back()[2] = p;
        res.push_back({p, b, INT_MAX});
      }
    }
    vector<int> ans;
    for (int i : queries) {
      for (int j = res.size() - 1; j >= 0; j--) {
        if (res[j][0] <= i) {
          ans.push_back(res[j][1]);
          break;
        }
      }
    }
    return ans;
  }
};
