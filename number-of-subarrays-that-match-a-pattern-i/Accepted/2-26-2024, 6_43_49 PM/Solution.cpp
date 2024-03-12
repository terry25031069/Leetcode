// https://leetcode.com/problems/number-of-subarrays-that-match-a-pattern-i

class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n = nums.size();
        vector<int> pat;
        for(int i = 0; i < n - 1; i++){
            int &a = nums[i], &b = nums[i+1];
            pat.push_back(a < b ? 1 : (a == b ? 0: -1));
        }
        int ans = 0, j;
        for(int i = 0; i <= pat.size() - pattern.size(); i++){
            for(j = 0; j < pattern.size(); j++){
                if(pat[i+j] != pattern[j]) break;
            }
            if(j == pattern.size()) ans++;
        }
        return ans;
    }
};