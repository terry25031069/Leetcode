// https://leetcode.com/problems/odd-string-difference

class Solution {
public:
    vector<int> diff(string s){
        vector<int> ans;
        for(int i = 1; i < s.size(); i++){
            ans.push_back(s[i] - s[i-1]);
        }
        return ans;
    }
    string oddString(vector<string>& words) {
        map<vector<int>, vector<string>> m;
        for(auto &str: words){
            m[diff(str)].push_back(str);
        }
        for(auto [k, v]: m){
            if(v.size() == 1) return v[0];
        }
        return "";
    }
};