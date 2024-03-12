// https://leetcode.com/problems/minimum-operations-to-write-the-letter-y-on-a-grid

class Solution {
public:
    bool chk(int x, int y, int n){
        int m = n / 2;
        if(x == y && y <= m) return true;
        if(x + y == n-1 && y > m) return true;
        if(x > m && y == m) return true;
        return false;
    }
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        int n = grid.size();
        int a[3] = {}, b[3] = {};
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(chk(i, j, n)){
                    a[grid[i][j]]++;
                }else b[grid[i][j]]++;
            }
        }
        // cout << a[0] << ' ' << a[1] << ' ' << a[2] << endl;
        // cout << b[0] << ' ' << b[1] << ' ' << b[2] << endl;
        cout << endl;
        int ans = 2500, sa = a[0] + a[1] + a[2], sb = b[0] + b[1] + b[2];
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(i != j){
                    ans = min(ans, sa - a[i] + sb - b[j]);
                    //cout << i << ' ' << j << ' ' << sa - a[i] + sb - b[j] << endl;
                }
            }
        }
        return ans;
    }
};