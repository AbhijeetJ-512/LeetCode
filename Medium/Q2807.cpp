// Definition for singly-linked list.
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
    ListNode *insertGreatestCommonDivisors(ListNode *head)
    {
        ListNode *cur = head;
        ListNode *front = head->next;
        while (front != nullptr)
        {
            ListNode *new_node = new ListNode(gcd(cur->val, front->val), front);
            cur->next = new_node;
            front = front->next;
            cur = cur->next->next;
        }
        return head;
    }

private:
    int gcd(int a, int b)
    {
        if (a == 0)
        {
            return 0;
        }
        if (b == 0)
        {
            return 0;
        }
        if (a == b)
        {
            return a;
        }
        if (a > b)
        {
            return gcd(a - b, b);
        }
        return gcd(a, b - a);
    }
};
