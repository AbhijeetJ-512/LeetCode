#include <iostream>
using namespace std;
class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int i = s.size() - 1;
        int ans = 0;
        while (s[i] == ' ')
        {
            i--;
        }
        while (i >= 0 && s[i] != ' ')
        {
            ans++;
            i--;
        }
        return ans;
    }
};