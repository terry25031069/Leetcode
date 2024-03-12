// https://leetcode.com/problems/spiral-matrix

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size(), m = matrix[0].size();
        int k = 0;
        int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
        int x = 0, y = 0;
        while(ans.size() < n * m){
            ans.push_back(matrix[x][y]);
            matrix[x][y] = -101;
            if(x + dx[k] < 0 || x + dx[k] == n ||
               y + dy[k] < 0 || y + dy[k] == m ||
                matrix[x + dx[k]][y + dy[k]] == -101) k = (k + 1) % 4;
            x += dx[k], y += dy[k];
        }
        return ans;
    }
};