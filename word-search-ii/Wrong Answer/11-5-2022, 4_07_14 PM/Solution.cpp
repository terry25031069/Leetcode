// https://leetcode.com/problems/word-search-ii

class Solution {
public:
    bool DFS(vector<vector<char>>& board, string s, int deep, int x, int y){
        if(deep == s.size()) return true;
        else if(s[deep] != board[x][y]) return false;
        else{
            bool ans = 0;
            int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
            for(int k = 0; k < 4; k++){
                if(x + dx[k] >= 0 && x + dx[k] < board.size() 
                && y + dy[k] >= 0 && y + dy[k] < board[0].size()){
                    ans |= DFS(board, s, deep + 1, x + dx[k], y + dy[k]);
                }
            }
            return ans;
        }
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                for(auto s: words){
                    if(DFS(board, s, 0, i, j) == 1){
                        ans.push_back(s);
                    }
                }
            }
        }
        return ans;
    }
};