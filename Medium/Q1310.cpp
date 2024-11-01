#include<vector>
using namespace std;
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> prefix(arr.size());
        prefix[0] = arr[0];
        for (int i = 1; i < arr.size(); ++i) {
            prefix[i] = prefix[i - 1] ^ arr[i];
        }
        vector<int> output;
        for( auto y : queries)
        {
            if(y[0] == 0)
            {
                output.push_back(prefix[y[1]]);
            }
            else
            {
                output.push_back(prefix[y[0]] ^ prefix[(y[1]-1)]);
            }
        }
        return output;
    }
};
