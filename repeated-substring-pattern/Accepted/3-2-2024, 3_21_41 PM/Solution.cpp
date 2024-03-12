// https://leetcode.com/problems/repeated-substring-pattern

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size(), i = 1, prev = 0; 
        vector<int> lps(n, 0);
        while(i < n){
            if(s[i] == s[prev]){
                lps[i] = prev + 1, i++, prev++;
            }else if(prev == 0){
                lps[i] = 0, i++;
            }else{
                prev = lps[prev - 1];
            }
        }
        int patternLen = n - lps.back();
        if(patternLen == n) return false;
        if(n % patternLen) return false;
        return true;
    }
};