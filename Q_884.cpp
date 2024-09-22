#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> words;
        stringstream ss1(s1);
        stringstream ss2(s2);
        string word;
        while(ss1 >> word)
        {
            words[word]++;
        }
        while(ss2 >> word)
        {
            words[word]++;
        }
        vector<string> answer;
        for(auto pair : words)
        {
            if(pair.second == 1)
            {
                answer.push_back(pair.first);
            }
        }
        return answer;
    }
};
