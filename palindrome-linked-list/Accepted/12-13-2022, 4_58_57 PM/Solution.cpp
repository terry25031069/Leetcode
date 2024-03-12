// https://leetcode.com/problems/palindrome-linked-list

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
    bool isPalindrome(ListNode* head) {
        vector<int> array, arrayr;
        while(head){
            array.push_back(head->val);
            head = head->next;
        }
        arrayr = array;
        reverse(arrayr.begin(), arrayr.end());
        if(array.size() == 0) return true; 
        for(int i = 0; i < array.size(); i++){
            if(array[i] != arrayr[i]) return false;
        }return true;
    }
};