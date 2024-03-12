// https://leetcode.com/problems/lexicographically-smallest-equivalent-string

class Solution {
public:
    int p[26] = {};
    int find(int n){
        return p[n] == n? n: p[n] = find(p[n]);
    }
    string smallestEquivalentString(string s1, string s2, string bs) {
        for(int i = 0; i < 26; i++) p[i] = i;
        for(int i = 0; i < s1.size(); i++){
            if(s1[i] < s2[i]){
                p[find(s2[i] - 'a')] = p[find(s1[i] - 'a')];
            }else p[find(s1[i] - 'a')] = p[find(s2[i] - 'a')];
        }
        for(int i = 0; i < bs.size(); i++){
            bs[i] = find(bs[i] -'a') + 'a';
        }
        return bs;
    }
};