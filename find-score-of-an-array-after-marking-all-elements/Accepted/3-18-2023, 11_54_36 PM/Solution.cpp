// https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements

class Solution {
public:
    using pii = pair<int, int>;
    long long findScore(vector<int>& nums) {
        priority_queue<pii, vector<pii>, greater<pii> > p;
        unordered_set<int> s;
        long long ans = 0;
        for(int i = 0; i < nums.size(); i++) p.push({nums[i], i});
        while(!p.empty()){
            pii top = p.top(); p.pop();
            //cout << top.first << ' ' << top.second << endl;
            if(s.find(top.second) == s.end()){ 
                //cout << "add " << top.first << ' ' << top.second << endl;
                s.insert(top.second);
                ans += top.first;
                if(top.second > 0) s.insert(top.second - 1);
                if(top.second < nums.size() - 1) s.insert(top.second + 1);
            }
        }
        return ans;
    }
};