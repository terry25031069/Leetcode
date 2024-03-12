// https://leetcode.com/problems/make-number-of-distinct-characters-equal

class Solution {
public:
    bool isItPossible(string word1, string word2) {
        map<char, int> m;
        for(auto i: word1) m[i]++;
        for(auto i: word2) m[i]++;
        if(m.size() % 2 == 0) return true;
        for(auto i: m){
            if(i.second == 1) return false;
        }
        return true;
    }
};