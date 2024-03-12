// https://leetcode.com/problems/smallest-value-after-replacing-with-sum-of-prime-factors

class Solution {
public:
    vector<bool> isprime;
    vector<int> prime;
    void build(int n){
        isprime.resize(n + 1, 1);
        isprime[0] = isprime[1] = 0;
        for(int i = 2; i < n + 1; i++){
            if(isprime[i]){
                for(int j = 2; i * j < n + 1; j++){
                    isprime[i * j] = 0;
                }
                prime.push_back(i);
            }
        }
    }
    int smallestValue(int n) {
        if(n < 6) return n;
        build(n);
        if(isprime[n]) return n;
        while(!isprime[n]){
            int idx = 0, ans = 0;
            while(n > 1){
                while(n % prime[idx] == 0) n /= prime[idx], ans += prime[idx];
                idx++;
            }
            n = ans;
        }
        return n;
    }
};