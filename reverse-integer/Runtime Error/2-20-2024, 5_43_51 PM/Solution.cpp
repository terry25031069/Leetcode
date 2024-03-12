// https://leetcode.com/problems/reverse-integer

class Solution {
public:
    int removeZero(int x){
        while(x % 10 == 0) x /= 10;
        return x;
    }
    int process(int x){
        while(x % 10 == 0) x /= 10;
        int ans = 0;
        while(x) ans = ans * 10 + x % 10, x /= 10;
        return ans;
    }
    int reverse(int x) {
        if(-10 < x && x < 10) return x;
        int sign = (x > 0 ? 1: -1), absX = removeZero(abs(x));
        if(absX != process(process(absX))) return 0;
        return sign * process(absX);
    }
};