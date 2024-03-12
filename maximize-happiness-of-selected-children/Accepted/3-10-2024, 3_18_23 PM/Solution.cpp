// https://leetcode.com/problems/maximize-happiness-of-selected-children

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        using ll = long long;
        sort(happiness.rbegin(), happiness.rend());
        ll ans = 0;
        for(int i = 0; i < k; i++){
            ans += max(ll(0), ll(happiness[i] - i));
        }
        return ans;
    }
};