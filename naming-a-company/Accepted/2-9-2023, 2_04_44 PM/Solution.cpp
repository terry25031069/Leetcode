// https://leetcode.com/problems/naming-a-company

class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        long long ans = 0;
        map<char, unordered_set<string>> m;
        for(auto s: ideas){
            m[s[0]].insert(s.substr(1));
        }
        for(char c = 'a'; c < 'z'; c++){
            for(char c1 = c + 1; c1 < 'z' + 1; c1++){
                unordered_set<string> u(m[c].begin(), m[c].end());
                u.insert(m[c1].begin(), m[c1].end());
                long long s1 = m[c].size(), s2 = m[c1].size(), su = s1 + s2 - u.size();
                ans += (s1 - su) * (s2 - su)* 2;
            }
        }
        return ans;
    }
};