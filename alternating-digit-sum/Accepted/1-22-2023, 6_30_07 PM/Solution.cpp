// https://leetcode.com/problems/alternating-digit-sum

class Solution {
public:
    int alternateDigitSum(int n) {
        string s = to_string(n);
        int ans = 0, sign = 1;
        for(auto c: s){
            ans += (c - '0') * (sign);
            sign = 0 - sign;
        }
        return ans;
    }
};