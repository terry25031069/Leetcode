// https://leetcode.com/problems/excel-sheet-column-title

class Solution {
public:
    string convertToTitle(int n) {
        vector<long long> v{1};
        for(int i = 0; v.back() < INT_MAX; i++) v.push_back(v.back() * 26);
        int idx = 0;
        while(n >= v[idx]) n -= v[idx++];
        string ans = "";
        while(idx){
            ans += (n / v[idx - 1]) + 'A';
            n %= v[idx - 1];
            idx--;
        }
        return ans;
    }
};