// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum

typedef long long ll;
#define MOD 1000000007

class Solution {
public:
    vector<ll> mul(vector<ll> l, vector<ll> r){
        int ls = l.size(), rs = r.size();
        vector<ll> ans(ls + rs - 1, 0);
        for(int i = 0; i < ls; i++){
            for(int j = 0; j < rs; j++){
                ans[i+j] += (l[i] * r[j]) % MOD;
                ans[i+j] %= MOD;
            }
        }
        //for(auto i: ans) cout << i << ' '; cout << endl;
        return ans;
    }
    int numRollsToTarget(int n, int k, int target) {
        if(target < n || target > k * n) return 0;
        if(target == n || target == k * n) return 1;
        vector<ll> ans = {1}, init = {};
        for(int i = 0; i <= k; i++){
            if(i == 0) init.emplace_back(0);
            else init.emplace_back(1);
        }
        for(int i = 0; i < n; i++){
            ans = mul(ans, init);
        }
        return ans[target];
    }
};