// https://leetcode.com/problems/integer-to-roman

class Solution {
public:
    string intToRoman(int num) {
        string s[4][10] = {
        {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}
        ,{"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"}
        ,{"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"}
        ,{"", "M", "MM", "MMM"}};
        int ans[4];
        for(int i = 0; i < 4; i++){
            ans[i] = num % 10;
            num /= 10;
        }
        string answer = "";
        for(int i = 3; i >= 0; i--){
            answer += s[i][ans[i]];
        } 
        return answer;
    }
};