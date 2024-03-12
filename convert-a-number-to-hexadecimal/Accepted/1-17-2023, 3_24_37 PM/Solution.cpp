// https://leetcode.com/problems/convert-a-number-to-hexadecimal

class Solution {
public:
    string toHex(int num) {
        string idx = "0123456789abcdef";
        long long tmp;
        if(num == 0) return "0";
        else if(num > 0){
            tmp = num;
        }else{
            tmp = 4294967296 + int64_t(num);
        }
        string s = "";
        while(tmp){
            s += idx[tmp % 16];
            tmp /= 16;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};