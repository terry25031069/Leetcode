// https://leetcode.com/problems/count-number-of-distinct-integers-after-reverse-operations

class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        set<int> s;
        for(auto i: nums){
            s.insert(i);
            string ss = to_string(i);
            reverse(ss.begin(), ss.end());
            s.insert(stoi(ss));
        }
        return s.size();
    }
};