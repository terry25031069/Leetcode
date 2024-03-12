// https://leetcode.com/problems/repeated-substring-pattern

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        map<char, int> m;
        for(char ch: s) m[ch]++;
        if(m.size() == 1 && s.size() > 1) return true;
        int g = __gcd((*m.begin()).second, (*(next(m.begin(), 1))).second);
        for(auto [k, v]: m) g = __gcd(g, v);
        if(g == 1) return false;
        for(int i = 0; i < s.size(); i += n / g){
            for(int j = 0; j < n / g; j++){
                //cout << i + j  << ' ' << j << ' ' << s[i + j] << ' ' << s[j] << endl;
                if(s[i + j] != s[j]) return false;
            }
        }
        return true;
    }
};