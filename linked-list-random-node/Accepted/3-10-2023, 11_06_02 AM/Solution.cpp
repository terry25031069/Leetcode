// https://leetcode.com/problems/linked-list-random-node

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
    int idx = 0;
    ListNode* ordHead;
    Solution(ListNode* head) {
        ordHead = head;
        while(head) idx++, head = head->next;
    }
    
    int getRandom() {
        ListNode* tmp = ordHead;
        int r = rand() % idx;
        while(r--) tmp = tmp->next;
        return tmp->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */