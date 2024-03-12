// https://leetcode.com/problems/kth-missing-positive-number

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int idx = 0, i = 1;
        for(; k; i++){
            if(idx < arr.size() && i == arr[idx]) idx++;
            else k--;
            if(!k) return i;
        }
        return i;
    }
};