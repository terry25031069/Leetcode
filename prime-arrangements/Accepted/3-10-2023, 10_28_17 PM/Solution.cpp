// https://leetcode.com/problems/prime-arrangements

class Solution {
public:
    int prime(int n){
        if(n == 1) return false;
        for(int i = 2; i * i <= n; i++){
            if(n % i == 0) return false;
        }
        return true;
    }
    int numPrimeArrangements(int n) {
        int a = 0, b = 0;
        for(int i = 1; i <= n; i++){
            if(prime(i)) a++;
            else b++;
        }
        long long ans = 1, mod = 1e9 + 7;
        while(a > 0) ans = ans * a % mod, a--;
        while(b > 0) ans = ans * b % mod, b--;
        return ans;
    }
};