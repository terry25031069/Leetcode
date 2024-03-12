// https://leetcode.com/problems/verifying-an-alien-dictionary

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        auto tmp = words;
        map<char, int> m;
        for(int i = 0; i < order.size(); i++) m[order[i]] = i;
        sort(tmp.begin(), tmp.end(), [&m](string a, string b){
            for(int i = 0; i < min(a.size(), b.size()); i++){
                if(a[i] != b[i]) return m[a[i]] < m[b[i]];
            }
            return a.size() < b.size();
        });
        return tmp == words;
    }
};