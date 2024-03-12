// https://leetcode.com/problems/max-consecutive-ones

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0, cnt = 0;
        nums.push_back(0);
        for(auto i: nums){
            if(i) cnt++;
            else{
                ans = max(ans, cnt);
                cnt = 0;
            }
        }
        return ans;
    }
};