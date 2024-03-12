// https://leetcode.com/problems/maximal-score-after-applying-k-operations

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0;
        priority_queue<int> q;
        for(auto i: nums){
            q.push(i);
        }
        while(k--){
            int tmp = q.top(); q.pop();
            ans += tmp, q.push((tmp + 2) / 3);
        }
        return ans;
    }
};