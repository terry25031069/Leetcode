// https://leetcode.com/problems/longest-subsequence-with-limited-sum

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        for(auto q: queries){
            int tmp = 0;
            for(int i: nums){
                if(i > q) break;
                else q  -= i, tmp++;
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};