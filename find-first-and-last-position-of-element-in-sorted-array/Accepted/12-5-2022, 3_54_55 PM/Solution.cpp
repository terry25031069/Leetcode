// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        nums.push_back(2e9);
        map<int, pair<int, int>>m; m.clear();
        int curNum = -1, low = -1, high = -1;
        for(int i = 0; i < nums.size(); i++){
            if(curNum != nums[i]){
                m[curNum] = {low + 1, high + 1};
                curNum = nums[i], low = high = i;
            }else{
                high++;
            }
        }
        //for(auto i: m) cout << i.second.first << ' ' << i.second.second << endl;
        vector<int>ans;
        if(m[target] == pair<int, int>{0, 0}){
            ans = {-1, -1};
        }else{
            ans = {m[target].first - 1, m[target].second - 1};
        }
        return ans;
    }
};