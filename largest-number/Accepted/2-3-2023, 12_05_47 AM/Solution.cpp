// https://leetcode.com/problems/largest-number

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b){
            string sa = to_string(a), sb = to_string(b);
            return sa + sb > sb + sa;
        });
        string ans = "";
        for(auto i: nums) ans += to_string(i);
        while(ans.size() > 1 && ans[0] == '0') ans.erase(ans.begin());
        return ans;
    }
};