#include<vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;
        int elements = n * m;
        int count = 0;
        int i = 0, j = 0, k = 0;
        while (count != elements) {
            while (j < n - k && count <= elements) {
                ans.push_back(matrix[i][j]);
                count++;
                j++;
            }
            j--;
            i++;
            while (i < m - k && count != elements) {
                ans.push_back(matrix[i][j]);
                count++;
                i++;
            }
            i--;
            j--;
            while (j >= k && count != elements) {
                ans.push_back(matrix[i][j]);
                count++;
                j--;
            }
            j++;
            i--;
            while (i > k && count != elements) {
                ans.push_back(matrix[i][j]);
                count++;
                i--;
            }
            i++;
            j++;
            k++;
        }
        return ans;
    }
};
