// https://leetcode.com/problems/is-subsequence

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int tmp = 0;
        for(auto c: t){
            if(c == s[tmp]) tmp++;
        }
        return tmp == s.size();
    }
};