// https://leetcode.com/problems/edit-distance

class Solution {
public:
    int dfs(string& w1, string& w2, int w1idx, int w2idx){
        if(!w1idx || !w2idx) return w1idx + w2idx;
        if(w1[w1idx-1] == w2[w2idx-1]) return dfs(w1, w2, w1idx-1, w2idx-1);
        else{
            int ins = dfs(w1, w2, w1idx, w2idx-1);
            int del = dfs(w1, w2, w1idx-1, w2idx);
            int rep = dfs(w1, w2, w1idx-1, w2idx-1);
            return min(ins, min(del, rep)) + 1;
        }
    }
    int minDistance(string word1, string word2) {
        return dfs(word1, word2, word1.size(), word2.size());
    }
};