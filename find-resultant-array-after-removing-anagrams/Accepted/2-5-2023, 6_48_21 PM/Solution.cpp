// https://leetcode.com/problems/find-resultant-array-after-removing-anagrams

class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        string tmps = "";
        for(auto s: words){
            string ss = s;
            sort(ss.begin(), ss.end());
            if(ss != tmps){
                ans.push_back(s);
                tmps = ss;
            }
        }
        return ans;
    }
};