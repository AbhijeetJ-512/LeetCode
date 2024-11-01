#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
public:
  int minExtraChar(string s, vector<string> &dictionary) {
    unordered_set<string> wordSet(dictionary.begin(), dictionary.end());
    int n = s.size();
    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
      dp[i] = dp[i - 1] + 1;
      for (int j = 0; j < i; ++j) {
        if (wordSet.find(s.substr(j, i - j)) != wordSet.end()) {
          dp[i] = min(dp[i], dp[j]);
        }
      }
    }

    return dp[n];
  }
};
