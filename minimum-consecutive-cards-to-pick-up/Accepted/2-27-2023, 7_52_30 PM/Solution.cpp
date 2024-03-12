// https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up

class Solution {
public:
    using pii = pair<int, int>;
    int minimumCardPickup(vector<int>& cards) {
        int ans = 1e7;
        map<int, pii> m;
        for(int idx = 0; idx < cards.size(); idx++){
            int i = cards[idx];
            if(m[i].first == 0) m[i].first = idx + 1;
            else{
                if(m[i].second){
                    m[i].first = m[i].second;
                }
                m[i].second = idx + 1;
                ans = min(ans, m[i].second - m[i].first);
            }
        }
        if(ans == 1e7) return -1;
        return ans + 1;
    }
};