// https://leetcode.com/problems/minimum-average-difference

class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        for(int i = 1; i < nums.size(); i++){
            nums[i] += nums[i - 1];
        }
        int diff = 1e9, record;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int slice0 = nums[i], slice1 = nums[n - 1] - nums[i];
            int avg0, avg1;
            avg0 = slice0 / (i + 1);
            if(n - i - 1 == 0) avg1 = 0;
            else avg1 = slice1 / (n - i - 1);
            cout << avg0 << ' ' << avg1 << endl;
            cout << abs(avg0 - avg1) << endl;

            if(diff > abs(avg0 - avg1)){
                diff = abs(avg0 - avg1);
                record = i;
            }
        }
        return record;
    }
};