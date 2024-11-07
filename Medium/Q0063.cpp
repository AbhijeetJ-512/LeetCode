#include <vector>
using namespace std;
class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    int n = obstacleGrid.size();
    int m = obstacleGrid[0].size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    if (obstacleGrid[0][0])
      return 0;
    for (int i = 0; i < n; ++i) {
      if (obstacleGrid[i][0] == 1) {
        break;
      }
      dp[i][0] = 1;
    }
    for (int i = 1; i < m; ++i) {
      if (obstacleGrid[0][i] == 1) {
        break;
      }
      dp[0][i] = 1;
    }
    for (int i = 1; i < n; ++i) {
      for (int j = 1; j < m; ++j) {
        dp[i][j] = (obstacleGrid[i][j]) ? 0 : dp[i - 1][j] + dp[i][j - 1];
      }
    }
    return dp[n - 1][m - 1];
  }
};
