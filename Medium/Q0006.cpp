#include<vector>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
        {
            return s;
        }
        bool goingdown = false;
        int i = 0;
        vector<string> rows(numRows,"");
        for(auto c : s)
        {
            rows[i] +=c;
            if(i == 0 || i == numRows-1)
            {
            goingdown = !goingdown;
            }
            i += goingdown ? 1:-1;
        }
        string solution;
        for(auto c : rows)
        {
            solution += c;
        }
        return solution;
    }
};
