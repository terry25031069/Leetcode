// https://leetcode.com/problems/intersection-of-two-linked-lists

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode*> s;
        while(headA){
            s.insert(headA);
            headA = headA -> next;
        }
        while(headB){
            auto it = s.find(headB);
            if(it != s.end()) return headB;
            headB = headB->next;
        }
        return NULL;
    }
};