// https://leetcode.com/problems/most-frequent-prime

class Solution {
public:
    int n, m;
    bool isprime[1000001];

    void build(){
        memset(isprime, 1, sizeof(isprime));
        isprime[0] = isprime[1] = 0;
        for(int i = 2; i < 1000001; i++){
            if(isprime[i]){
                for(int j = 2; i * j <= 1e6; j++){
                    isprime[i * j] = 0;
                }
            }
        }
    }

    bool check(int x, int y){
        if(x < 0 || x > n - 1 || y < 0 || y > m - 1) return false;
        return true;
    }

    int mostFrequentPrime(vector<vector<int>>& mat) {
        build();
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
                        if(isprime[tmp] && tmp > 10) cnt[tmp]++;
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