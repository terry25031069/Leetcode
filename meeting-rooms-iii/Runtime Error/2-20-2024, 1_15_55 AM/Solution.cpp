// https://leetcode.com/problems/meeting-rooms-iii

#define F first
#define S second

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> ans(n + 1, 0);
        sort(meetings.begin(), meetings.end());
        using pii = pair<int, int>;
        priority_queue<pii, vector<pii>, greater<pii>> ava, tmp;
        for(int i = 0; i < n; i++){
            ava.push({0, i});
        }
        for(auto &v: meetings){
            pii top = ava.top();
            int ava_time = top.F;
            while(!ava.empty() && ((ava.top().F <= v[0]) || (ava.top().F > v[0] && ava.top().F == ava_time))){
                pii tmpele = ava.top(); ava.pop();
                tmp.push({tmpele.S, tmpele.F});
            }
            pii tmpele = tmp.top(); tmp.pop();
            int num = tmpele.F, time = tmpele.S;
            if(time <= v[0]){
                ava.push({v[1], num});
            }else{
                ava.push({time + v[1] - v[0], num});
            }
            ans[num]++;
            while(!tmp.empty()){
                ava.push({tmp.top().S, tmp.top().F});
                tmp.pop();
            }
        }
        return max_element(ans.begin(), ans.end()) - ans.begin();
    }
};