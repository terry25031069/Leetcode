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
        return to_string(stoi(ans));
    }
};