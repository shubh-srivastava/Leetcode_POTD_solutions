// 14th June 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
int res;
ListNode* left;
    void dfs(ListNode* right){
        if (right == nullptr){
            return;
        }

        dfs(right->next);
        res = max(res, left->val + right->val);
        left = left->next;
    }

    int pairSum(ListNode* head){
        left = head;
        res = 0;

        dfs(head);
        return res;
    }
};