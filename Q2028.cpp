#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        vector <int> ans;
        int total = rolls.size()+n;
        int sum = 0;
        for(auto x:rolls)
        {
            sum+=x;
        }
        float remaining = mean*total - sum;
        if(remaining/n > 6 || remaining/n < 1)
        {
            return ans;
        }
        ans.assign(n,1);
        remaining -= n;
        int i = 0;
        while(remaining !=0)
        {
            ans[i] +=1;
            i++;
            remaining--;
            if( i == n)
            {
                i=0;
            }
        }
        return ans;
    }
};
