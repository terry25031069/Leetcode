// https://leetcode.com/problems/zigzag-conversion

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        vector<string>tmp(numRows);
        int vy = -1, i = 0;
        for(auto c: s){
            tmp[i].push_back(c);
            if(i == numRows - 1 || i == 0) vy = -vy;
            i += vy;
        }
        string ans = "";
        for(auto i: tmp) ans += i;
        return ans;
    }
};