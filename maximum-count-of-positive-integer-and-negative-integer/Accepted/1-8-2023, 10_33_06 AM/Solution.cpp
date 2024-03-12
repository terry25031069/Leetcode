// https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int a, b;
        a = b = 0;
        for(auto i: nums){
            if(i < 0) a++;
            if(i > 0) b++;
        }
        return max(a, b);
    }
};