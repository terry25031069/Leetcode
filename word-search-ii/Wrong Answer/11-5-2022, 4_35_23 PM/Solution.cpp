// https://leetcode.com/problems/word-search-ii

class Solution {
public:
    bool DFS(vector<vector<char>>& board, string s, 
                int deep, int x, int y, vector<vector<bool>>visit){
        if(s[deep] != board[x][y]) return false;
        else{
            bool ans = 0;
            int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
            for(int k = 0; k < 4; k++){
                if(deep + 1 == s.size()) return true;
                if(x + dx[k] >= 0 && x + dx[k] < board.size() && 
                    y + dy[k] >= 0 && y + dy[k] < board[0].size() &&
                    visit[x + dx[k]][y + dy[k]] == 0){
                    auto tmp = visit;
                    tmp[x + dx[k]][y + dy[k]] = 1;
                    ans |= DFS(board, s, deep + 1, x + dx[k], y + dy[k], tmp);
                }
            }
            return ans;
        }
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        map<string, int> sset;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                for(auto s: words){
                    vector<vector<bool>>tmp(board.size(), vector<bool>(board[0].size(), 0));
                    if(DFS(board, s, 0, i, j, tmp) == 1 && sset[s] == 0){
                        ans.push_back(s);
                        sset[s] = 1;
                    }
                }
            }
        }
        return ans;
    }
};