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
        int idx = 0;
        priority_queue<int> p;
        while(k--){
             while(idx < proj.size() && proj[idx].first <= w) p.push(proj[idx++].second);
             if(p.empty()) return w;
             else{
                 w += p.top(); p.pop();
             } 
        }
        return w;
    }
};