// https://leetcode.com/problems/maximum-ice-cream-bars

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int ans;
        sort(costs.begin(), costs.end());
        for(ans = 0; ans < costs.size() && coins >= costs[ans]; ans++){
            coins -= costs[ans];
        }
        return ans;
    }
};