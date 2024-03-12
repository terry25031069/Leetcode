// https://leetcode.com/problems/difference-between-element-sum-and-digit-sum-of-an-array

class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int a = 0, b = 0;
        for(auto i: nums) a += i;
        for(auto i: nums){
            for(char j: to_string(i)) b += j - '0';
        }
        return abs(b - a);
    }
};