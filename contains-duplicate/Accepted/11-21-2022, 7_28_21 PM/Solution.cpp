// https://leetcode.com/problems/contains-duplicate

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int>check;
        for(auto i: nums){
            check[i]++;
            if(check[i] > 1) return true;
        }
        return false;
    }
};