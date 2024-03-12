// https://leetcode.com/problems/bitwise-and-of-numbers-range

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if(left == right) return left;
        int i, ans = left & right;
        for(i = 0; i < 31 && left <= right - (1 << i); i++){
            ans &= (2147483647 ^ (1 << i));
            //cout << (2147483647 ^ (1 << i)) << ' ' << ans << endl;
        }
        if(i == 31) return 0;
        return ans;
    }
};