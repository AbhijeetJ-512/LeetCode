#include <string>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
public:
  int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2) {
    int ans = 0;
    unordered_set<string> prefixmap;
    for (int num : arr1) {
      string str = to_string(num);
      string prefix = "";
      for (char c : str) {
        prefix += c;
        prefixmap.insert(prefix);
      }
    }
    for (int num : arr2) {
      string str = to_string(num);
      string prefix = "";
      for (char c : str) {
        prefix += c;
        if (prefixmap.find(prefix) != prefixmap.end()) {
          ans = (ans > prefix.size()) ? ans : prefix.size();
        } else {
          break;
        }
      }
    }
    return ans;
  }
};
