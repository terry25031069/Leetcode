// https://leetcode.com/problems/excel-sheet-column-number

class Solution {
public:
    int titleToNumber(string columnTitle) {
        string s = columnTitle;
        vector<int> bas{1};
        for(int i = 1; i < 7; i++)bas.push_back(bas.back() * 26);
        reverse(s.begin(), s.end());
        s.resize(7, 64);
        int ans = 0;
        for(int i = 0; i < 7; i++){
            ans += bas[i] * (s[i] - 64);
        }
        return ans;
    }
};