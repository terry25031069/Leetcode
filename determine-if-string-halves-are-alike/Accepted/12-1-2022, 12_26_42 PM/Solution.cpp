// https://leetcode.com/problems/determine-if-string-halves-are-alike

class Solution {
public:
    bool a[200] = {};
    bool halvesAreAlike(string s) {
        a['a'] = a['e'] = a['i'] = a['o'] = a['u'] = 1;
        string s1 = s.substr(0, s.size() / 2), s2 = s.substr(s.size() / 2, s.size() / 2);
        int ans1 = 0, ans2 = 0;
        for(auto i: s1){
            if(a[tolower(i)] == 1) ans1++;
        }
        for(auto i: s2){
            if(a[tolower(i)] == 1) ans2++;
        }
        return ans1 == ans2;
    }
};