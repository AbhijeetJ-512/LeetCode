#include<vector>
using namespace std;
class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans;
        for (int i = 0; i < expression.size(); ++i) {
            char op = expression[i];
            if (op == '+' || op == '-' || op == '*') {
                vector<int> num1 = diffWaysToCompute(expression.substr(0, i));
                vector<int> num2 = diffWaysToCompute(expression.substr(i + 1));
                for (auto a : num1) {
                    for (auto b : num2) {
                        if (op == '+')
                            ans.push_back(a + b);
                        else if (op == '-')
                            ans.push_back(a - b);
                        else
                            ans.push_back(a * b);
                    }
                }
            }
        }
        if (ans.empty())
            ans.push_back(stoi(expression));
        return ans;
    }
};
