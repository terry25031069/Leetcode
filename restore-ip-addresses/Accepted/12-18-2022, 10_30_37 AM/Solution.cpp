// https://leetcode.com/problems/restore-ip-addresses

class Solution {
public:
    vector<string> ans;
    void dfs(string s, int idx, int part, vector<string>tmp){
        if(idx == s.size() && part == 4){
            string subans = "";
            for(int i = 0; i < tmp.size(); i++){
                subans += tmp[i];
                if(i < tmp.size() - 1) subans += ".";
            }
            ans.push_back(subans);
        }
        for(int i = 0; i + idx < s.size() && i < 3; i++){
            string ttmp = s.substr(idx, i + 1);
            if(stoi(ttmp) < 256 && to_string(stoi(ttmp)) == ttmp){
                tmp.push_back(ttmp);
                dfs(s, idx + i + 1, part + 1, tmp);
                tmp.pop_back();
            }else{
                break;
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        ans.clear();
        dfs(s, 0, 0, {});
        return ans;
    }
};