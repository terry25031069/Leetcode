// https://leetcode.com/problems/distinct-prime-factors-of-product-of-array

class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        map<int, int> m;
        for(auto &n: nums){
            for(int i = 2; i <= n; i++){
                while(n % i == 0) m[i]++, n /= i;
            }
        }
        return m.size();
    }
};