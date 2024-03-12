// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string

class Solution {
public:
    string removeDuplicates(string s) {
        vector<char>v;
        for(auto i:s){
            if(!v.empty() && v.back() == i)v.pop_back();
            else v.push_back(i);
        }
        string ans(v.begin(), v.end());
        return ans;
    }
};