// https://leetcode.com/problems/max-pair-sum-in-an-array

class Solution {
public:
    int maxSum(vector<int>& nums) {
        map<int, vector<int>> m;
        for(int n: nums){
            string s = to_string(n);
            vector<char> v(s.begin(), s.end());
            int max_digit = *max_element(v.begin(), v.end()) - '0';
            m[max_digit].push_back(n);
        }
        int ma = -1;
        for(auto &[k, v]: m){
            if(v.size() < 2) continue;
            sort(v.begin(), v.end());
            ma = max(ma, v[0] + v[1]);
        }
        return ma;
    }
};