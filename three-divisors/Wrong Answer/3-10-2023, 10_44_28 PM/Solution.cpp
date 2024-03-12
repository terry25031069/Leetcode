// https://leetcode.com/problems/three-divisors

class Solution {
public:
    bool isThree(int n) {
        if(n < 4) return false;
        if(n == 4) return true;
        if(n % 2 == 0) return false; 
        if(sqrt(n) == int(sqrt(n))){
            int k = sqrt(n);
            for(int i = 2; i * i <= k; i++){
                if(k % i == 0) return false;
            }
            return true;
        }
        return true;
    }
};