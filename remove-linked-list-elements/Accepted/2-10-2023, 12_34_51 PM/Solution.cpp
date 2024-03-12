// https://leetcode.com/problems/remove-linked-list-elements

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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *ans, *prev;
        while(head && head->val == val) head = head->next;
        ans = prev = head;
        while(head){
            if(head->val == val){
                prev->next = head->next;
            }else{
                prev = head;
            }
            head = head->next;
        }
        return ans;
    }
};