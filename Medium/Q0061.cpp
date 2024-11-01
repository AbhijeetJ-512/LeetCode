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
    ListNode* rotateRight(ListNode* head, int k) {

        if (head == nullptr || k == 0 || head->next == nullptr) {
            return head;
        }
        int length = 1;
        ListNode* cur = head;
        while (cur->next != nullptr) {
            cur = cur->next;
            length++;
        }
        cur->next = head;
        k = length - (k % length);

        for (int i = 0; i < k; ++i) {
            cur = cur->next;
        }
        head = cur->next;
        cur->next = nullptr;
        return head;
    }
};
