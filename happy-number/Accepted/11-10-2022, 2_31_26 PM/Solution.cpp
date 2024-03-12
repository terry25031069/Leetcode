// https://leetcode.com/problems/happy-number

class Solution {
public:
    bool isHappy(int n) {
        map<int, int>cycle;
        while(cycle[n] == 0 && n != 1){
            cycle[n] = 1;
            int tmp = n, ans = 0;
            while(tmp){
                ans += (tmp % 10) * (tmp % 10);
                tmp /= 10;
            }
            n = ans;
            cout << n << endl;
        }
        return (n == 1);
    }
};