// https://leetcode.com/problems/eliminate-maximum-number-of-monsters

#define F first
#define S second

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        using pii = pair<int, int>;
        vector<pii> moninfo;
        for(int i = 0; i < dist.size(); i++){
            moninfo.push_back({dist[i], speed[i]});
        }
        sort(moninfo.begin(), moninfo.end(), [](pii a, pii b){
            return a.F * b.S < a.S * b.F;
        });
        for(auto i: moninfo){
            cout << i.F << ' ' << i.S << endl;
        }
        int cnt = 1;
        auto &a = moninfo;
        for(int i = 1; i < moninfo.size(); i++){
            if(a[i].F * a[i-1].S >= (a[i-1].F + a[i-1].S) * a[i].S) cnt++;
            else break;
        }
        return cnt;
    }
};
