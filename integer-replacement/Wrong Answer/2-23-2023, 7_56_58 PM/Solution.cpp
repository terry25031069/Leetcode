// https://leetcode.com/problems/integer-replacement

class Solution {
public:
    int integerReplacement(int n) {
        int ans = 0;
        while(n > 1){
            if(n & 3 == 3) n++;
            else if(n & 1) n--;
            else n >>= 1;
            ans++;
        }
        return ans;
    }
};