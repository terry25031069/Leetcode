// https://leetcode.com/problems/sort-colors

class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int>cnt(3, 0);
        for(int i: nums) cnt[i]++;
        int cur = 0;
        for(auto &i: nums){
            while(cnt[cur] == 0) cur++;
            i = cur, cnt[cur]--;
        }
    }
};