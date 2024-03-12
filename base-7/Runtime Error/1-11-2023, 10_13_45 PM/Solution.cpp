// https://leetcode.com/problems/base-7

class Solution {
public:
    string convertToBase7(int num) {
        int sign = (num > 0? 1 : (num == 0? 0: -1));
        int tmp = abs(num);
        string ans = "";
        while(tmp){
            ans += to_string(tmp % 7);
            tmp /= 7;
        }
        reverse(ans.begin(), ans.end());
        int fans = sign * stoi(ans);
        return to_string(fans);
    }
};