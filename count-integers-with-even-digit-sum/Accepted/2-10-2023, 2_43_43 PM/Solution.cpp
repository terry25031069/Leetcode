// https://leetcode.com/problems/count-integers-with-even-digit-sum

class Solution {
public:
    int ds(int n){
        string s = to_string(n);
        int ans = 0;
        for(auto c: s) ans += c - '0';
        return ans;
    }
    int countEven(int num) {
        int ans = 0;
        for(int i = 1; i <= num; i++){
            if(ds(i) % 2 == 0) ans++;
        }
        return ans;
    }
};