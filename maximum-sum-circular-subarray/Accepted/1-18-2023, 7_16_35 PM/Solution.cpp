// https://leetcode.com/problems/maximum-sum-circular-subarray

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int mi, mini, ma, maxi, tot;
        mi = mini = 1e6;
        ma = maxi = -1e6;
        tot = 0;
        for(auto i: nums){
            tot += i;
            ma = max(ma + i, i), maxi = max(maxi, ma);
            mi = min(mi + i, i), mini = min(mini, mi);
        }
        //cout << maxi << ' ' << mini << ' ' << tot << endl;
        if(tot == mini) return maxi;
        return max(tot - mini, maxi);
    }
};