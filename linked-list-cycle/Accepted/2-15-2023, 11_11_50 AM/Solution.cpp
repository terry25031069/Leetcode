// https://leetcode.com/problems/linked-list-cycle

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        if(!head) return false;
        while(fast && fast->next){
            fast = fast->next->next; 
            slow = slow->next;
            if(fast == slow) return true;
        }
        return false;
    }
};