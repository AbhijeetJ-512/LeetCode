#include<iostream>
using namespace std;

// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


 //Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(head == nullptr)
        {
            return true;
        }
        else if(root == nullptr)
        {
            return false;
        }
        return dfs(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
    bool dfs(ListNode* head, TreeNode* root) {
        if (head == nullptr) {
            return true; 
        }
        if (root == nullptr || root->val != head->val) {
            return false;
        }
        return dfs(head->next, root->left) || dfs(head->next, root->right);
    }
};
