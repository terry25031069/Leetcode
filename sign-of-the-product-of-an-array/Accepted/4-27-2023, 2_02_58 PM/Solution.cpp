// https://leetcode.com/problems/sign-of-the-product-of-an-array

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int ans = 1;
        for(int i: nums){
            ans *= (i > 0 ? 1:(i == 0? 0 : -1));
        }
        return ans;
    }
};