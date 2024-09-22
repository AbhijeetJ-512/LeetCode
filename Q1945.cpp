using namespace std;
class Solution {
private:
    string letters_to_numbers(string s) {
        string solution = "";
        for (auto x : s) {
            solution += to_string(x - 'a' + 1);
        }
        return solution;
    }

public:
    int getLucky(string s, int k) {
        int sum;
        string n = letters_to_numbers(s);
        for (int i = 0; i < k; ++i) {
            sum = 0;
            for (auto x : n) {
                sum += x - '0';
            }
            n = to_string(sum);
        }
        return stoi(n);
    }
};
