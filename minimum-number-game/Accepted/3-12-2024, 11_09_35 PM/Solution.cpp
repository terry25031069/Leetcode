// https://leetcode.com/problems/minimum-number-game

class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i: nums) pq.push(i);
        vector<int> ans;
        while(!pq.empty()){
            int tmp1 = pq.top(); pq.pop();
            int tmp2 = pq.top(); pq.pop();
            ans.push_back(tmp2);
            ans.push_back(tmp1);
        }
        return ans;
    }
};