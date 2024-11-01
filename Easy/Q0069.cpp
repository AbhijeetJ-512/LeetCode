#include<iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if(x == 0 || x == 1) return x;
        double ans = x/2;
        for(int i=0;i<20;i++)
        {
            ans = 0.5*(ans + (x/ans));
        }
        return static_cast<int> (ans);
    }
};
