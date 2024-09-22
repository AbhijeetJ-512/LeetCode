#include<vector>
using namespace std;
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        int cur = 1;
        for (size_t i = 0; i < n; ++i) {
            ans.push_back(cur);

            if (cur * 10 <= n) {
                cur *= 10;
            } else {
                if (cur >= n) {
                    cur /= 10;
                }
                cur++;
                while (cur % 10 == 0) {
                    cur /= 10;
                }
            }
        }
        return ans;
    }

};
