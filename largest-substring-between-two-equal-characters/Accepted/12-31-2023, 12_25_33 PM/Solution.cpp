// https://leetcode.com/problems/largest-substring-between-two-equal-characters

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        using pii = pair<int, int>;
        unordered_map<char, pii> m;
        for(int i = 0; i < s.size(); i++){
            char ch = s[i];
            if(!m[ch].first) m[ch].first = i + 1;
            else m[ch].second = i + 1;
        }
        int ans = -1;
        for(auto [k, v]: m){
            if(v.first && v.second){
                ans = max(ans, v.second - v.first - 1);
            }
        }
        return ans;
    }
};