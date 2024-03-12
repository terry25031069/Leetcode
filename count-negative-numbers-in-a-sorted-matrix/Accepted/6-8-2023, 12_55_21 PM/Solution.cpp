// https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0, i = 0, j = grid[0].size() - 1;
        while(i < grid.size()){
            //cout << i << ' ' << j << endl;
            while(j > -1 && grid[i][j] < 0) j--;
            ans += grid[0].size() - j - 1;
            i++;
            if(j < grid[0].size() - 1)j++;
        }
        return ans;
    }
};