// https://leetcode.com/problems/split-the-array

class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        map<int, int> m;
        for(int n: nums){
            m[n]++;
            if(m[n] > 2) return false;
        }
        return true;
    }
};