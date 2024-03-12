// https://leetcode.com/problems/count-collisions-of-monkeys-on-a-polygon

class Solution {
public:
    int mod = 1000000007;
    long long f(int n){
        long long mod = 1000000007;
        if(n == 0) return 1;
        if(n == 1) return 2;
        long long x = f(n / 2) % mod;
        if(n & 1) return (x * x * 2) % mod;
        return (x * x) % mod;
    }
    int monkeyMove(int n) {
        return (f(n) - 2 + mod) % mod;
    }
};