// https://leetcode.com/problems/n-queens-ii

class Solution {
public:
    int ans = 0;
    int col[10], d1[21], d2[21];
    vector<string> board;
    void dfs(int n, int depth, vector<string> &tmp){
        if(depth == n){
            ans++;
            return;
        }
        for(int i = 0; i < n; i++){
            if(tmp[depth][i] == '.' && col[i] == 0 && d1[depth-i+10] == 0 && d2[depth+i] == 0){
                tmp[depth][i] = 'Q';
                col[i] = d1[depth-i+10] = d2[depth+i] = 1;
                dfs(n, depth + 1, tmp);
                tmp[depth][i] = '.';
                col[i] = d1[depth-i+10] = d2[depth+i] = 0;
            }
        }
    }
    int totalNQueens(int n) {
        board = vector<string>(n, string(n, '.'));
        memset(col, 0, sizeof(col));
        memset(d1, 0, sizeof(d1));
        memset(d2, 0, sizeof(d2));
        dfs(n, 0, board);
        return ans;
    }
};