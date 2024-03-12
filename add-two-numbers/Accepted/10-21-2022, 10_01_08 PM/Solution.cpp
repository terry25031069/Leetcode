// https://leetcode.com/problems/add-two-numbers

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* ans = new ListNode(0), *tmp;
        tmp = ans;
        while(l1 || l2){
            tmp->val += l1->val + l2->val;
            if(tmp->val > 9) carry = 1, tmp->val -= 10;
            if(l1->next == NULL && l2->next){
                l1->next = new ListNode(0);
            }
            if(l2->next == NULL && l1->next){
                l2->next = new ListNode(0);
            }
            l1 = l1->next, l2 = l2->next;
            if(l1 || l2 || carry){
                tmp->next = new ListNode(carry);
            }
            tmp = tmp->next;
            carry = 0;
        }
        return ans;
    }
};