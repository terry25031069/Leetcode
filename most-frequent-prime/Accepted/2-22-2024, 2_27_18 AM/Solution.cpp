// https://leetcode.com/problems/most-frequent-prime

class Solution {
public:
    int n, m;

    bool primeCheck(int num){
        for(int i = 2; i * i <= num; i++){
            if(num % i == 0) return false;
        }
        return true;
    }

    bool check(int x, int y){
        if(x < 0 || x > n - 1 || y < 0 || y > m - 1) return false;
        return true;
    }

    int mostFrequentPrime(vector<vector<int>>& mat) {
        int ans = 0, anscnt = 0;
        map<int, int> cnt;
        n = mat.size(), m = mat[0].size();
        vector<int>dx = {0, 1, 1, 1, 0, -1, -1, -1};
        vector<int>dy = {1, 1, 0, -1, -1, -1, 0, 1};
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                for(int k = 0; k < 8; k++){
                    int cx = i, cy = j; 
                    int tmp = mat[i][j];
                    while(check(cx + dx[k], cy + dy[k])){
                        tmp = tmp * 10 + (mat[cx + dx[k]][cy + dy[k]]);
                        if(primeCheck(tmp) && tmp > 10) cnt[tmp]++;
                        cx += dx[k], cy += dy[k];
                    }
                }
            }
        }
        if(!cnt.size()) return -1;
        else{
            for(auto [k, v]: cnt){
                if(v >= anscnt && k > ans) ans = k, anscnt = v;
            }
        }
        return ans;
    }
};