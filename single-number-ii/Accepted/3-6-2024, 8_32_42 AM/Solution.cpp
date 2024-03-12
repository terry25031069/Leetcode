// https://leetcode.com/problems/single-number-ii

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < 32; i++){
            int bit = 0;
            for(int n: nums){
                bit += (n >> i) & 1;
            }
            ans += (1 << i) * (bit % 3);
        }
        return ans;
    }
};