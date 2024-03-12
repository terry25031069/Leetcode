// https://leetcode.com/problems/third-maximum-number

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int>s;
        for(auto i: nums) s.insert(i);
        if(s.size() < 3) return *s.rbegin();
        auto it = s.rbegin();
        for(int cnt = 1; cnt < 3; it++, cnt++);
        return *it;
    }
};