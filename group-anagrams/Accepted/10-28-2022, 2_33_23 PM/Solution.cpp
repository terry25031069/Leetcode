// https://leetcode.com/problems/group-anagrams

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, int>idx; int index = 0;
        vector<vector<string>> ans(1);
        for(auto i: strs){
            string tmp = i;
            sort(tmp.begin(), tmp.end());
            if(idx[tmp] == 0) idx[tmp] = ++index, ans.push_back({i});
            else{
                ans[idx[tmp]].push_back(i);
            }      
        }
        ans.erase(ans.begin());
        return ans;
    }
};