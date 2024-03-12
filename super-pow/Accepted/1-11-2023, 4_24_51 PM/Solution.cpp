// https://leetcode.com/problems/super-pow

class Solution {
public:
    int superPow(int a, vector<int>& b) {
        int ans = 1;
        a %= 1337;
        for(auto digit: b){
            int t = ans;
            for(int i = 0; i < 9; i++){
                ans *= t;
                ans %= 1337;
            }
            //cout << ans << endl;
            for(int i = 0; i < digit; i++){
                ans *= a;
                ans %= 1337;
            }
            //cout << ans << endl;
        }
        return ans;
    }
};