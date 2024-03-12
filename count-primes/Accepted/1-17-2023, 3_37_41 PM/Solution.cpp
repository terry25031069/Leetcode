// https://leetcode.com/problems/count-primes

class Solution {
public:
    int countPrimes(int n) {
        if(n < 2) return 0;
        int i;
        vector<int>isprime(n + 1, 1);
        isprime[0] = isprime[1] = 0;
        for(i = 2; i <= n; i++){
            if(isprime[i]){
                for(int j = 2; i * j <= n; j++){
                    isprime[i * j] = 0;
                }
            }
        }
        for(int i = 1; i <= n; i++){
            isprime[i] += isprime[i-1];
        }
        return isprime[n-1];
    }
};