// https://leetcode.com/problems/minimum-average-difference

class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        double avg0, avg1, diff; int record = 0;
        avg0 = avg1 = 0;
        vector<int> slice0 = {}, slice1 = nums;
        for(int i = 0; i < nums.size(); i++){
            avg1 += nums[i];
        }
        avg1 /= nums.size();
        diff = abs(int(avg1) - int(avg0));
        reverse(slice1.begin(), slice1.end());
        for(int i = 0; i < nums.size(); i++){
            cout << i << ' ' << avg0 << ' ' << int(avg0) << ' ' << avg1 << ' ' << int(avg1) << endl;
            avg0 *= slice0.size(), avg0 += slice1.back(); slice0.push_back(slice1.back()), avg0 /= slice0.size();
            avg1 *= slice1.size(); avg1 -= slice1.back(), slice1.pop_back();
            if(slice1.size() > 0) avg1 /= slice1.size();
            else avg1 = 0;
            if(diff > abs(int(avg0) - int(avg1))){
                diff = abs(int(avg0) - int(avg1));
                record = i;
            }
        }
        return record;
    }
};