#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int count = 0;
        for (auto word : words) // word from words
        {
            bool check = true;
            for (auto letter : word) // letter from each word
            {
                int i = allowed.size();
                while(i)
                {
                    if(allowed[i-1] == letter)
                    {
                        break;
                    }
                    i--;
                }
                if(i == 0)
                {
                    check = false;
                }

            }
            count += (check) ? 1 : 0;
        }
        return count++;
    }
};
