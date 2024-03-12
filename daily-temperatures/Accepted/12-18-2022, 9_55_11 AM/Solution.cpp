// https://leetcode.com/problems/daily-temperatures

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>ans(temperatures.size()), tmp, idx;
        for(int i = 0; i < temperatures.size(); i++){
            while(tmp.size() && tmp.back() < temperatures[i]){
                ans[idx.back()] = i - idx.back();
                tmp.pop_back();
                idx.pop_back();
            }
            tmp.push_back(temperatures[i]);
            idx.push_back(i);
            // for(auto i: tmp) cout << i << ' '; cout << endl;
            // for(auto i: idx) cout << i << ' '; cout << endl;
            // cout << endl;
        }
        return ans;
    }
};