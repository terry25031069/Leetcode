// https://leetcode.com/problems/determine-if-two-strings-are-close

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> w1(26, 0), w2(26, 0);
        set<int> s1, s2;
        for(auto i: word1) w1[i- 'a']++, s1.insert(i - 'a');
        for(auto i: word2) w2[i- 'a']++, s2.insert(i - 'a');
        sort(w1.begin(), w1.end());
        sort(w2.begin(), w2.end());
        if(s1.size() > s2.size()) s2.swap(s1);
        for(auto i: s1){
            if(s2.find(i) == s2.end()) return false;
        }
        if(w1.size() != w2.size()) return false;
        for(int i = 0; i < w1.size(); i++){
            if(w1[i] != w2[i]) return false; 
        }
        return true;
    }
};