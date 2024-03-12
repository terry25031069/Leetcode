// https://leetcode.com/problems/bitwise-and-of-numbers-range

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if(left == right) return left;
        int ans = left & right;
        for(int i = 0; left + (1 << i) <= right; i++){
            if(i == 31) return 0;
            ans &= (2147483647 ^ (1 << i));
            //cout << (2147483647 ^ (1 << i)) << ' ' << ans << endl;
        }
        return ans;
    }
};