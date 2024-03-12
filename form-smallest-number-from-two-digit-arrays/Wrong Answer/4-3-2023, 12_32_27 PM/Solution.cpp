// https://leetcode.com/problems/form-smallest-number-from-two-digit-arrays

class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        int cnt[10] = {};
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        for(int i: nums1) cnt[i]++;
        for(int i: nums2){
            if(cnt[i]) return i;
        }
        return nums1.front() * 10 + nums2.front();
    }
};