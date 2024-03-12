// https://leetcode.com/problems/count-elements-with-maximum-frequency

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> cnt(101, 0);
        for(int i: nums) cnt[i]++;
        int ma = *max_element(cnt.begin(), cnt.end());
        int ans = 0;
        for(int i: nums) if(cnt[i] == ma) ans++;
        return ans;
    }
};