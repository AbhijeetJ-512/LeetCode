#include <iostream>
using namespace std;
class Solution
{
public:
    int minChanges(int n, int k)
    {
        if ((n & k) != k)
        {
            return -1;
        }
        else if (n == k)
        {
            return 0;
        }
        k = n & (~k);
        n = 0;
        while (k)
        {
            n += (k & 1) == 1 ? 1 : 0;
            k >>= 1;
        }
        return n;
    }
};