// https://leetcode.com/problems/three-consecutive-odds

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        if(arr.size() < 3) return false;
        for(int i = 0; i < arr.size() - 3; i++){
            if(!(arr[i] & 1) && !(arr[i+1] & 1) && !(arr[i+2] & 1)){
                return false;
            }
        }
        return true;
    }
};