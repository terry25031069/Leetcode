// https://leetcode.com/problems/out-of-boundary-paths

class Solution {
public:
    const int N = 1e9 + 7;
    int a[51][51] = {}, b[51][51] = {};
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    long long ans = 0;
    void printboard(int m, int n, int a[51][51]){
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cout << a[i][j] << " \n"[j == n-1];
            }
        }
        cout << endl;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        a[startRow][startColumn] = 1;
        for (int step = 0; step < maxMove; step++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(a[i][j] && b[i][j] == 0){
                        for(int k = 0; k < 4; k++){
                            if(i + dx[k] < 0 || i + dx[k] >= m || j + dy[k] < 0 || j + dy[k] >= n){
                                ans += a[i][j];                
                                ans %= N;
                            }else{
                                a[i+dx[k]][j+dy[k]] = (a[i+dx[k]][j+dy[k]] + a[i][j]) % N;
                                b[i+dx[k]][j+dy[k]] = 1;
                            }
                        }
                        a[i][j] = 0;
                    }
                }
            }
            memset(b, 0, sizeof(b));
            //printboard(m, n, a);
        }
        return ans;
    }
};