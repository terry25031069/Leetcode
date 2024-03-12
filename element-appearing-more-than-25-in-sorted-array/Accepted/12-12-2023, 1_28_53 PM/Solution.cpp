// https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        for(int i = 0; i < n - n / 4; i++){
            if(arr[i] == arr[i+n/4]) return arr[i];
        }
        return 0;
    }
};