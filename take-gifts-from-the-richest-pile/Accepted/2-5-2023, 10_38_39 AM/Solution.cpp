// https://leetcode.com/problems/take-gifts-from-the-richest-pile

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> q;
        for(auto i: gifts) q.push(i);
        while(k--){
            int t = q.top(); q.pop();
            q.push(floor(sqrt(t)));
        }
        long long ans = 0;
        while(!q.empty()){
            ans += q.top(); q.pop();
        }
        return ans;
    }
};