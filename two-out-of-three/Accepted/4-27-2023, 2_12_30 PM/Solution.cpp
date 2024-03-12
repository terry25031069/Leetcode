// https://leetcode.com/problems/two-out-of-three

class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        set<int> s1(nums1.begin(), nums1.end()), s2(nums2.begin(), nums2.end()), s3(nums3.begin(), nums3.end());
        map<int, int> m;
        for(auto i: s1) m[i]++;
        for(auto i: s2) m[i]++;
        for(auto i: s3) m[i]++;
        vector<int> v;
        for(auto [k, val]: m){
            if(val > 1) v.push_back(k);
        }
        return v;
    }
};