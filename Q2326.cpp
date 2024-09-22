#include<vector>
using namespace std;
// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m, vector<int>(n, -1));
        ListNode* cur = head;
        int i = 0, j = 0, k = 0;
        while (cur != nullptr) {
            while (j < n-k && cur != nullptr) {
                matrix[i][j] = cur->val;
                cur = cur->next;
                j++;
            }
            j--;
            i++;
            while (i < m-k && cur != nullptr) {
                matrix[i][j] = cur->val;
                cur = cur->next;
                i++;
            }
            i--;
            j--;
            while (j >=k  && cur != nullptr) {
                matrix[i][j] = cur->val;
                cur = cur->next;
                j--;
            }
            j++;
            i--;
            while (i > k && cur != nullptr) {
                matrix[i][j] = cur->val;
                cur = cur->next;
                i--;
            }
            i++;
            j++;
            k++;
        }
        return matrix;
    }
};
