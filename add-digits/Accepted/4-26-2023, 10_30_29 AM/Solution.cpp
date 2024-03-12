// https://leetcode.com/problems/add-digits

class Solution {
public:
    int addDigits(int num) {
        if(!num) return 0;
        int tmp = num % 9;
        if(tmp) return tmp;
        return 9;
    }
};