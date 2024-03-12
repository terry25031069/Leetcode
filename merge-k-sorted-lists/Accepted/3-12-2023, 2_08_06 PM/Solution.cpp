// https://leetcode.com/problems/merge-k-sorted-lists

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *ans, *head; 
        if(lists.size() == 0) return NULL;
        using pil = pair<int, ListNode*>;
        vector<pil> v;
        for(auto i: lists){
            while(i) v.push_back({i->val, i}), i = i->next;
        }
        if(!v.size()) return NULL;
        sort(v.begin(), v.end(), [](pil a, pil b){
            return a.first < b.first;
        });
        for(int i = 0; i < v.size() - 1; i++){
            v[i].second->next = v[i+1].second;
        }
        v[v.size() - 1].second->next = NULL;
        return v[0].second;
    }
};