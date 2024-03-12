// https://leetcode.com/problems/largest-divisible-subset

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> ans(n), prev(n);
        fill_n(ans.begin(), n, 1);
        for(int i = 0; i < n; i++) prev[i] = i;
        for(int i = 1; i < n; i++){
            for(int j = i - 1; j > -1; j--){
                if(nums[i] % nums[j] == 0 && ans[j] + 1 > ans[i]){
                    prev[i] = j;
                    ans[i] = ans[j] + 1;
                }
            }
        }
        for(int i: ans) cout << i << ' '; cout << endl;
        for(int i: prev) cout << i << ' '; cout << endl;
        int coord = max_element(ans.begin(), ans.end()) - ans.begin();
        vector<int> ret_ans{nums[coord]};
        while(coord != prev[coord]){
            coord = prev[coord];
            ret_ans.push_back(nums[coord]);
        }
        return ret_ans;
    }
};