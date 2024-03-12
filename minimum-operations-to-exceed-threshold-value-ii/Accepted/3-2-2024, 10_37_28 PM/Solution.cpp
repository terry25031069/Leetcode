// https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-ii

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        using ll = long long;
        priority_queue<ll, vector<ll>, greater<ll> > pq;
        for(int i: nums) pq.push(i);
        int ans = 0;
        while(pq.top() < k){
            ans += 1;
            ll a = pq.top(); pq.pop(); 
            ll b = pq.top(); pq.pop();
            pq.push(min(a, b) * 2 + max(a, b));
        }
        return ans;
    }
};