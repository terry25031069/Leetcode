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
        v.erase(v.begin());
        ll ans = -1;
        for(int i = 2; i < nums.size(); i++){
            if(nums[i] < v[i-1]) ans = ll(nums[i]) + ll(v[i-1]);
        }
        return ans;
    }
};