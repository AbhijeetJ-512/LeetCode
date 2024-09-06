#include <vector>
#include <set>
using namespace std;
//  Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *modifiedList(vector<int> &nums, ListNode *head)
    {
        std::set<int> num_set;
        for (auto element : nums)
        {
            num_set.insert(element);
        }
        while (head != nullptr && num_set.find(head->val) != num_set.end())
        {
            head = head->next;
        }
        if (head == nullptr)
        {
            return nullptr;
        }
        else
        {
            ListNode *prev = head;
            ListNode *cur = head->next;
            while (cur != nullptr)
            {
                if (num_set.find(cur->val) != num_set.end())
                {
                    prev->next = cur->next;
                    cur = prev->next;
                }
                else
                {
                    cur = cur->next;
                    prev = prev->next;
                }
            }
        }
        return head;
    }
};