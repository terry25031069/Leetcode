// https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty

class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int, int> m;
        int ans = 0;
        for(int n: nums) m[n]++;
        for(auto [k, v]: m){
            if(v < 2) return -1;
            else{
                ans += (v + 2) / 3;
            }
        }
        return ans;
    }
};