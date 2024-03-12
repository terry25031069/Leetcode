// https://leetcode.com/problems/repeated-dna-sequences

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.size() < 11) return {};
        vector<string> ans;
        map<string, int> m;
        string ss = ' ' + s.substr(0, 9);
        for(int i = 0; i < s.size() - 9; i++){
            ss.erase(ss.begin());
            ss += s[i + 9];
            m[ss]++;
        }
        for(auto [k, v]: m){
            if(v > 1) ans.push_back(k);
        }
        return ans;
    }
};