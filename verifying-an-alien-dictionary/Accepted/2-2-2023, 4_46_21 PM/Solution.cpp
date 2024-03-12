// https://leetcode.com/problems/verifying-an-alien-dictionary

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<char, char> m;
        for(int i = 0; i < order.size(); i++) m[order[i]] = 'a' + i;
        for(auto &s: words){
            for(auto &c: s){
                c = m[c];
            }
        }
        for(int i = 0; i < words.size() - 1; i++){
            cout << words[i] << ' ';
            if(words[i] > words[i+1]) return false;
        }
        return true;
    }
};