// https://leetcode.com/problems/ipo

class Solution {
public:
    using pii = pair<int, int>;
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pii> proj;
        for(int i = 0; i < profits.size(); i++){
            proj.push_back({capital[i], profits[i]});
        }
        sort(proj.begin(), proj.end());
        while(k--){
            pii findele = {w + 1, 0};
            auto tmp = upper_bound(proj.begin(), proj.end(), findele) - proj.begin();
            w += proj[tmp-1].second;
            proj.erase(proj.begin() + tmp - 1);
        }
        return w;
    }
};