#include <string>
using namespace std;
class Solution {
public:
  string longestDiverseString(int a, int b, int c) {
    string answer = "";
    short int size = a + b + c;
    short int cur_a = 0, cur_b = 0, cur_c = 0;
    while (size) {
      if ((a >= b && a >= c && cur_a != 2) ||
          (a > 0 && (cur_b == 2 || cur_c == 2))) {
        answer += 'a';
        cur_a++;
        cur_b = 0;
        cur_c = 0;
        a--;
      } else if ((b >= a && b >= c && cur_b != 2) ||
                 (b > 0 && (cur_a == 2 || cur_c == 2))) {
        answer += 'b';
        cur_b++;
        cur_a = 0;
        cur_c = 0;
        b--;
      } else if ((c >= a && c >= b && cur_c != 2) ||
                 (c > 0 && (cur_b == 2 || cur_a == 2))) {
        answer += 'c';
        cur_c++;
        cur_a = 0;
        cur_b = 0;
        c--;
      }
      size--;
    }
    return answer;
  }
};
