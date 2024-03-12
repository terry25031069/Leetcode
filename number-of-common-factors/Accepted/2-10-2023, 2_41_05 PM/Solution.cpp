// https://leetcode.com/problems/number-of-common-factors

class Solution {
public:
    int commonFactors(int a, int b) {
        int g = __gcd(a, b);
        int ans = 0;
        for(int i = 1; i * i <= g; i++){
            if(g % i == 0){
                if(i * i == g) ans++;
                else ans += 2;
            }
        }
        return ans;
    }
};