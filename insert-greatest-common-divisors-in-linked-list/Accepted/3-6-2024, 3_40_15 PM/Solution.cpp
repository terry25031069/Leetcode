// https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list

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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* ans = head, *cur = head;
        while(cur->next){
            ListNode *tmp = cur->next;
            ListNode *gcdNode = new ListNode(__gcd(cur->val, tmp->val));
            //cout << cur->val << ' ' << tmp->val << ' ' << __gcd(cur->val, tmp->val);
            cur->next = gcdNode, gcdNode->next = tmp;
            cur = tmp, tmp = tmp->next;
        }
        return ans;
    }
};