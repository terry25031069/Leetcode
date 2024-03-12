// https://leetcode.com/problems/middle-of-the-linked-list

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
    ListNode* middleNode(ListNode* head) {
        if(!head->next) return head;
        if(!head->next->next) return head->next;
        ListNode* ans = head, *fast = head;
        while(fast && fast->next){
            fast = fast->next;
            if(fast) fast = fast->next;
            ans = ans->next;
        }
        return ans;
    }
};