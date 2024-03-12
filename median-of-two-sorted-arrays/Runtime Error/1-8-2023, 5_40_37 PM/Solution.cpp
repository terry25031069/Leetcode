// https://leetcode.com/problems/median-of-two-sorted-arrays

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>v; 
        int n1, n2; n1 = n2 = 0;
        while(n1 < nums1.size() || n2 < nums2.size()){
            while(n1 < nums1.size() && (n2 == nums2.size() || nums1[n1] <= nums2[n2])){
                v.push_back(nums1[n1]);
                n1++;
            }
            while(n2 < nums2.size() && (n1 == nums2.size() || nums1[n1] >= nums2[n2])){
                v.push_back(nums2[n2]);
                n2++;
            }
        }
        for(auto i: v) cout << i << ' '; cout << endl;
        if(v.size() & 1) return v[v.size() / 2];
        else return (double(v[v.size() / 2 - 1]) + double(v[v.size() / 2])) / 2;
    }
};