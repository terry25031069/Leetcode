// https://leetcode.com/problems/remove-nth-node-from-end-of-list

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head->next) return NULL;
        ListNode *dummy = new ListNode(0); dummy->next = head;
        ListNode *ans = head, *f = dummy, *s = head;
        while(n--) s = s->next;
        while(s) f = f->next, s = s->next;
        //cout << f->val << endl;
        if(f == dummy) return ans->next;
        if(f->next) f->next = f->next->next;
        return ans;
    }
};