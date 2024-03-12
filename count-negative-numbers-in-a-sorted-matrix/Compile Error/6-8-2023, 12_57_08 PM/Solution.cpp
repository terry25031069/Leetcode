// https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0, i = 0, j = grid[0].size() - 1, N = grid.size() M = j;
        while(i < N){
            //cout << i << ' ' << j << endl;
            while(j > -1 && grid[i][j] < 0) j--;
            ans += M - j;
            i++;
            if(j < M)j++;
        }
        return ans;
    }
};