// https://leetcode.com/problems/find-the-highest-altitude

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> v{0};
        for(auto i: gain) v.push_back(v.back() + i);
        return *max_element(v.begin(), v.end());
    }
};