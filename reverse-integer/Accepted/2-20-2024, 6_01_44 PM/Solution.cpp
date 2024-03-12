// https://leetcode.com/problems/reverse-integer

class Solution {
public:
    int removeZero(int x){
        while(x % 10 == 0) x /= 10;
        return x;
    }
    int process(int x){
        int ans = 0;
        while(x){
            if(ans >= 214748365 || (ans >= 214748364 && x % 10 > 7)) return 0;
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        return ans;
    }
    int reverse(int x) {
        if(-10 < x && x < 10) return x;
        int sign = (x > 0 ? 1: -1), absX = removeZero(abs(x));
        return sign * process(absX);
    }
};