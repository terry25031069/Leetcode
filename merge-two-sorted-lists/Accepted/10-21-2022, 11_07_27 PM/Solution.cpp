// https://leetcode.com/problems/merge-two-sorted-lists

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* init = new ListNode(0), *tmp;
        tmp = init;
        while(list1 && list2){
            ListNode* newNode;
            if(list1->val < list2->val){
                cout << list1->val << ' ';
                newNode = new ListNode(list1->val);
                list1 = list1->next;
            }
            else{
                cout << list2->val << ' ';
                newNode = new ListNode(list2->val);
                list2 = list2->next;
            }
            tmp->next = newNode, tmp = tmp->next;
        }
        while(!list1 && list2){
            cout << list2->val << ' ';
            tmp->next = new ListNode(list2->val), list2 = list2->next, tmp = tmp->next;
        }
        while(list1 && !list2){
            cout << list1->val << ' ';
            tmp->next = new ListNode(list1->val), list1 = list1->next, tmp = tmp->next;
        }
        cout << endl;
        return init->next;
    }
};