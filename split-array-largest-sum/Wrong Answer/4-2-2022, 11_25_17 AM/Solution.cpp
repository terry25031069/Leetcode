// https://leetcode.com/problems/split-array-largest-sum

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int L = -1, R = 1e9;
        for(auto i: nums) L = max(L, i);
        while(L < R){
            int M = L + R >> 1, cnt = 0, tmpsum = 0;
            for(int i = 0; i < nums.size(); i++){
                if(tmpsum + nums[i] <= M){
                    tmpsum += nums[i];
                }else{
                    cnt += 1;
                    tmpsum = nums[i];
                }
            }
            if(tmpsum > 0) cnt += 1;
            if(cnt > m) L = M + 1;
            else R = M - 1;
        }
        int ans = L + R >> 1;
        return ans;
    }
};