// https://leetcode.com/problems/palindrome-number

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        else{
            int tmp = 0, xx = x;
            while(xx){
                tmp *= 10;
                tmp += xx % 10;
                xx /= 10;
            }
            if(tmp == x) return true;
            return false;
        }
    }
};