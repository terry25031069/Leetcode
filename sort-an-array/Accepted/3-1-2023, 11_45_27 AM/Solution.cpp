// https://leetcode.com/problems/sort-an-array

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i: nums) pq.push(i);
        vector<int> ans;
        while(!pq.empty()) ans.push_back(pq.top()), pq.pop();
        return ans;
    }
};