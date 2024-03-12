// https://leetcode.com/problems/palindrome-partitioning

class Solution {
public:
    vector<vector<string>> ans;
    bool isPalin(string s){
        string re = s;
        reverse(re.begin(), re.end());
        return re == s;
    }
    void dfs(int idx, string s, vector<string> tmp){
        if(idx == s.size()){
            ans.push_back(tmp);
        }else{
            for(int i = idx + 1; i <= s.size(); i++){
                if(isPalin(s.substr(idx, i - idx))){
                    auto ttmp = tmp;
                    ttmp.push_back(s.substr(idx, i - idx));
                    dfs(i, s, ttmp);
                }
            }
        }
    }
    vector<vector<string>> partition(string s) {
        dfs(0, s, {});
        return ans;
    }
};