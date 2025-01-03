#include <algorithm>
#include <string>
using namespace std;
class Solution {
public:
  bool isAnagram(string s, string t) {
    if (s.size() != t.size()) {
      return false;
    } else {
      sort(s.begin(), s.end());
      sort(t.begin(), t.end());
      for (int i = 0; i < s.size(); ++i) {
        if (s[i] != t[i]) {
          return false;
        }
      }
    }
    return true;
  }
};
