// https://leetcode.com/problems/maximum-strong-pair-xor-i

class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                if(abs(nums[i] - nums[j]) <= min(nums[i], nums[j]))
                ans = max(ans, (nums[i] ^ nums[j]));
            }
        }
        return ans;
    }
};