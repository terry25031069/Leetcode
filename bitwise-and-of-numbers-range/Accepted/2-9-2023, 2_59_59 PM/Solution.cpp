// https://leetcode.com/problems/bitwise-and-of-numbers-range

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        bitset<32> ans;
        if(!left || !right) return 0;
        for(int i = 0; (left >> i) > 0; i++){
            if(left / (1 << i + 1) == right / (1 << i + 1) &&
                right % (1 << i + 1) >= (1 << i) &&
                left % (1 << i + 1) >= (1 << i))
                ans[i] = 1;
            else ans[i] = 0;
        }
        return ans.to_ulong();
    }
};