// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cnt = prices[0], ans = 0;
        for(int i = 1; i < prices.size(); i++){
            if(cnt < prices[i]){
                ans += (prices[i] - cnt);
            }
            cnt = prices[i];
        }        
        return ans;
    }
};