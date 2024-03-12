// https://leetcode.com/problems/maximize-happiness-of-selected-children

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.rbegin(), happiness.rend());
        int ans = 0;
        for(int i = 0; i < k; i++) ans += happiness[i];
        return ans - k + 1;
    }
};