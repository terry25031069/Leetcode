// https://leetcode.com/problems/sort-array-by-increasing-frequency

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int, int>m; 
        for(auto i: nums)m[i]++;
        sort(nums.begin(), nums.end(), [=, &m](int a, int b){
            if(m[a] != m[b])return m[a] < m[b];
            return a > b;
        });
        return nums;
    }
};