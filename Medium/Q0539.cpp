#include<vector>
using namespace std;

class Solution {
public:
    int convertToMinutes(const string& time) {
        int hours = stoi(time.substr(0, 2));
        int minutes = stoi(time.substr(3, 2));
        return hours * 60 + minutes;
    }
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;
        for (auto time : timePoints) {
            minutes.push_back(convertToMinutes(time));
        }
        sort(minutes.begin(), minutes.end());

        int minDiff = INT_MAX;

        for (size_t i = 0; i < minutes.size() - 1; ++i) {
            minDiff = min(minDiff, minutes[i + 1] - minutes[i]);
        }
        minDiff = min(minDiff, (1440 - minutes.back() + minutes.front()));

        return minDiff;
    }
};
