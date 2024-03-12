// https://leetcode.com/problems/repeated-substring-pattern

class Solution {
public:
    bool isPrime(int n){
        if(n % 2 == 0) return false;
        if(n % 3 == 0) return false;
        for(int i = 5, j = 2; i * i <= n; i += j, j = 6 - j){
            if(n % i == 0) return false;
        }
        return true;
    }
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        if(isPrime(n)) return false;
        map<char, int> m;
        for(char ch: s) m[ch]++;
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