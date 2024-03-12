// https://leetcode.com/problems/count-primes

class Solution {
public:
    int countPrimes(int n) {
        int i;
        vector<int>isprime(n + 20, 1);
        isprime[0] = isprime[1] = 0;
        for(i = 2; i <= n; i++){
            if(isprime[i]){
                for(int j = 2; i * j <= n; j++){
                    isprime[i * j] = 0;
                }
            }
        }
        for(int i = 1; i <= n; i++){
            cout << isprime[i] << ' ';
            isprime[i] += isprime[i-1];
        }
        return isprime[n];
    }
};