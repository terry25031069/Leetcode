// https://leetcode.com/problems/add-digits

class Solution {
public:
    int addDigits(int num) {
        while(num > 9){
            int tmp = num, ans = 0;
            while(tmp){
                ans += tmp % 10, tmp /= 10;
            }
            num = ans;
        }
        return num;
    }
};