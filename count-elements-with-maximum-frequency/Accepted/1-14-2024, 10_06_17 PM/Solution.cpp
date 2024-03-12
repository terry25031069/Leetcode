// https://leetcode.com/problems/count-elements-with-maximum-frequency

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> c(101, 0);
        for(int n: nums) c[n]++;
        int ma = *max_element(c.begin(), c.end());
        int ans = 0;
        for(int n: c) if(n == ma) ans += n;
        return ans;
    }
};