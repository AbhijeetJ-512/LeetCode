#include <iostream>
using namespace std;

//  * Definition for singly-linked list.
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
    ListNode *swapPairs(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode *newhead = head->next;
        ListNode *prev = nullptr;
        while (head != nullptr && head->next != nullptr)
        {
            ListNode *first = head;
            ListNode *second = head->next;

            first->next = second->next;
            second->next = first;

            if (prev != nullptr)
            {
                prev->next = second;
            }

            head = first->next;
            prev = first;
        }
        return newhead;
    }
};