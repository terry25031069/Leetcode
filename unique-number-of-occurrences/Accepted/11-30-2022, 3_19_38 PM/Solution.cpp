// https://leetcode.com/problems/unique-number-of-occurrences

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> orr, orr1;
        for(auto i: arr) orr[i]++;
        for(auto i: orr) orr1[i.second]++;
        return orr1.size() == orr.size();
    }
};