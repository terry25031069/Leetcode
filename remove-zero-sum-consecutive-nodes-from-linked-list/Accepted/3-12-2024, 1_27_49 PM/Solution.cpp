// https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list

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
    bool removeZeroSum(vector<int>& v){
        vector<int> sum(v.size() + 1, 0);
        int i, j;
        for(i = 0; i < v.size(); i++){
            for(j = 0; j <= i; j++){
                sum[j] += v[i];
                if(sum[j] == 0) goto yee;
            }
        }
        yee:
        if(i == v.size()) return false;
        else{
            //cout << "Erase from " << j << " to " << i << endl;
            v.erase(v.begin() + j, v.begin() + i + 1);
            return true;
        }
    }
    ListNode* removeZeroSumSublists(ListNode* head) {
        vector<int> v;
        while(head){
            if(head->val) v.push_back(head->val);
            head = head->next;
        }
        bool chk = 1;
        while(chk){
            chk = removeZeroSum(v);
        }
        ListNode *tmp = new ListNode(0), *ans = tmp;
        for(int num: v){
            tmp->next = new ListNode(num);
            tmp = tmp->next;
        }
        return ans->next;
    }
};