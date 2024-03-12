// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l, r, li, ans = 0;
        l = r = 1e9, li = -1;
        for(int i = 0; i < prices.size(); i++){
            if(prices[i] > r) r = prices[i];
            if(prices[i] < l) r = l = prices[i];
            ans = max(r - l, ans);
        }
        return ans;
    }
};