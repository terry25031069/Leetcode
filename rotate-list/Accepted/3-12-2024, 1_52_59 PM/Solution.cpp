// https://leetcode.com/problems/rotate-list

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0 || !head) return head;
        vector<int> v;
        while(head) v.push_back(head->val), head = head->next;
        k %= v.size();
        rotate(v.begin(), v.end() - k, v.end());
        //for(int num: v) cout << num << ' '; cout << endl;
        ListNode *tmp = new ListNode(v[0]), *ans = tmp;
        for(int i = 1; i < v.size(); i++){
            tmp->next = new ListNode(v[i]);
            tmp = tmp->next;
        }
        return ans;
    }
};