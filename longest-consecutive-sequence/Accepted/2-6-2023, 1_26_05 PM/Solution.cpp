// https://leetcode.com/problems/longest-consecutive-sequence

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() < 2) return nums.size();
        set<int> s;
        for(int i: nums) s.insert(i);
        s.insert(2e9);
        int ans = 1, cur = 2e9, cus = 0;
        for(int i: s){
            if(i != cur + 1){
                ans = max(ans, cus);
                cur = i, cus = 1;
            }else cus++, cur++;
        }
        return ans;
    }
};