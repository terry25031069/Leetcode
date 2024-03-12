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
    vector<ListNode*>ans;
    ListNode* middleNode(ListNode* head) {
        while(head){
            ans.push_back(head);
            head = head->next;
        }
        int loc = ans.size() / 2;
        return ans[loc];
    }
};