// https://leetcode.com/problems/excel-sheet-column-title

class Solution {
public:
    string convertToTitle(int n) {
        vector<long long> v{26};
        for(int i = 0; v.back() < INT_MAX; i++) v.push_back(v.back() * 26);
        int idx = 0; n--;
        while(n > v[idx]) n -= v[idx++];
        string ans = "";
        while(idx--){
            ans += (n / v[idx]) + 'A';
            n %= v[idx];
        }ans += n + 'A';
        return ans;
    }
};