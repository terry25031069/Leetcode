// https://leetcode.com/problems/minimum-operations-to-make-array-equal-ii

class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        long long sum = 0, sumpos = 0;
        for(int i = 0; i < nums1.size(); i++){
            int tmp = (nums1[i] - nums2[i]);
            if(tmp % k) return -1;
            sum += tmp;
            if(tmp > 0) sumpos += tmp;
        }
        if(sum) return -1;
        return sumpos / k;
    }
};