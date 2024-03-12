// https://leetcode.com/problems/intersection-of-two-arrays

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int>s1(nums1.begin(), nums1.end()), s2(nums2.begin(), nums2.end());
        vector<int> ans;
        std::set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), std::back_inserter(ans));
        return ans;
    }
};