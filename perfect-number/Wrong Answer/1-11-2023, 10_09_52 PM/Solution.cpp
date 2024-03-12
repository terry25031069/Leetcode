// https://leetcode.com/problems/perfect-number

class Solution {
public:
    bool checkPerfectNumber(int num) {
        int ans = 0;
        for(int i = 2; i * i < num; i++){
            if(num % i == 0) ans += i + num / i;
        }
        //cout << ans << endl;
        ans++;
        return num == ans;
    }
};