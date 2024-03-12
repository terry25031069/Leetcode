// https://leetcode.com/problems/maximum-odd-binary-number

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        if(s.size() < 3){
            sort(s.begin(), s.end());
            return s;
        }else{
            sort(s.begin(), s.end(), greater<char>());
            return s.substr(1, s.size() -1) + '1';
        }
    }
};