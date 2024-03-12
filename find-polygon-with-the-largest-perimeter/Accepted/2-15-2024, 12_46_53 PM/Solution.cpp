// https://leetcode.com/problems/find-polygon-with-the-largest-perimeter

class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        using ll = long long;
        vector<ll> v{0};
        for(auto n: nums){
            v.push_back(n + v.back());
        }
        ll ans = -1;
        for(int i = 2; i < nums.size(); i++){
            if(nums[i] < v[i]) ans = ll(nums[i]) + ll(v[i]);
        }
        return ans;
    }
};