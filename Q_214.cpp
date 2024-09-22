using namespace std;
class Solution {
public:
    string shortestPalindrome(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        if (s.size() == 0 || s.size() == 1) {
            return s;
        }
        string reversed = s;
        reverse(reversed.begin(),reversed.end());
        int s_size = s.size();
        for(int i=0;i<s_size;++i)
        {
            if(!memcmp(s.c_str(),reversed.c_str()+i, s_size-i))
            {
                return reversed.substr(0,i)+ s;
            }
        }
        return reversed+s;
    }
};
