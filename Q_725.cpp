#include<iostream>
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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k,nullptr);
        int count=0;
        ListNode* cur = head;
        while(cur!=nullptr)
        {
            count++;
            cur = cur->next;
        }
        int partSize = count / k;
        int extraNodes = count % k;

        cur = head;
        for (int i = 0; i < k && cur != nullptr; ++i) {
            ans[i] = cur;
            int currentPartSize = partSize + (i < extraNodes ? 1 : 0);            
            for (int j = 1; j < currentPartSize; ++j) {
                cur = cur->next;
            }
            ListNode* nextPart = cur->next;
            cur->next = nullptr;
            cur = nextPart;
        }
        
        return ans;
    }
};
