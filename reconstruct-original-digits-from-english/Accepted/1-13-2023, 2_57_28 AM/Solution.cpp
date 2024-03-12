// https://leetcode.com/problems/reconstruct-original-digits-from-english

class Solution {
public:
    int cnt[26] = {};
    int a[10] = {};
    string ans = "";
    void lead(int num, string s){
        a[num] += cnt[s[0] - 'a'];
        for(auto c: s) cnt[c - 'a'] -= a[num];
    }
    string originalDigits(string s) {
        for(auto c: s){
            cnt[c - 'a']++;
        }
        lead(0, "zero");
        lead(2, "wto");
        lead(8, "gieht");
        lead(6, "xis");
        lead(4, "uofr");
        lead(7, "seven");
        lead(5, "vife");
        lead(9, "inne");
        lead(3, "htree");
        lead(1, "one");
        for(int i = 0; i < 10; i++) ans += string(a[i], '0' + i);
        return ans;
    }
};