#include<iostream>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.size()-1;
        int n = b.size()-1;
        int abit, bbit,sum=0;
        int c=0;
        string ans = "";
        while(m>=0 || n>=0 || c)
        {
            abit = (m >= 0) ? a[m] - '0' : 0;
            bbit = (n >= 0) ? b[n] - '0' : 0;
            sum = abit + bbit + c;
            if(sum == 0)
            {
                ans = '0' + ans;
                c = 0;
            }
            else if(sum == 1)
            {
                ans = '1' + ans;
                c = 0;
            }
            else if(sum == 2)
            {
                ans = '0' + ans;
                c = 1;
            }
            else if(sum == 3)
            {
                ans = '1' + ans;
                c = 1;
            }
            m--;
            n--;
        }
        
        return ans;
    }
};
