// https://leetcode.com/problems/best-poker-hand

class Solution {
public:
    using pii = pair<int, int>;
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        vector<pii> v;
        for(int i = 0; i < ranks.size(); i++){
            v.push_back({suits[i] - 'a', ranks[i]});
        }
        sort(v.begin(), v.end());
        if(v[0].first == v[4].first) return "Flush";
        else{
            map<int, int> m, m1;
            for(auto c: v) m[c.second]++;
            for(auto [k, v]: m) {
                if(v) m1[v]++;
            }
            if(m1[3] == 1 || m1[4] == 1) return "Three of a Kind";
            if(m1[2]) return "Pair";
            return "High Card";
        }
    }
};