// https://leetcode.com/problems/factorial-trailing-zeroes

class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        while(n){
            ans += n / 5;
            n /= 5;
        }
        return ans;
    }
};