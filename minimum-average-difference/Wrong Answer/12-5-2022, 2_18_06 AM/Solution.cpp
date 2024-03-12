// https://leetcode.com/problems/minimum-average-difference

class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        vector<long long>num; 
        for(int i: nums) num.push_back(int64_t(i));
        for(int i = 1; i < num.size(); i++){
            num[i] += num[i - 1];
        }
        int diff = 1e9, record;
        int n = num.size();
        for(int i = 0; i < n; i++){
            int slice0 = num[i], slice1 = num[n - 1] - num[i];
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