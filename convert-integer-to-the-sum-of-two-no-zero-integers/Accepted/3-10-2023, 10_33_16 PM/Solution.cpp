// https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers

class Solution {
public:
    bool chk(int n){
        while(n){
            if(n % 10 == 0) return false;
            n /= 10;
        }
        return true; 
    }
    vector<int> getNoZeroIntegers(int n) {
        for(int i = 1; i <= n / 2; i++){
            int a = i, b = n - i;
            if(chk(a) && chk(b)){
                return {a, b};
            }
        }
        return {-1, -1};
    }
};