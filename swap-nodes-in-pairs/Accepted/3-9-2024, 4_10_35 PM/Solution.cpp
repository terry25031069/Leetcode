// https://leetcode.com/problems/swap-nodes-in-pairs

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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;    
        ListNode* dummy = new ListNode(0); dummy->next = head;
        ListNode *first = dummy, *second = head, *third = head->next;
        while(1){
            //cout << first->val << ' ' << second->val << ' ' << third->val << endl;
            second->next = third->next;
            third->next = second;
            first->next = third;
            if(!second->next || !second->next->next) break;
            else{
                first = second;
                second = first->next;
                third = second->next;
            }
        }
        return dummy->next;
    }
};