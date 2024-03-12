// https://leetcode.com/problems/nth-digit

class Solution {
public:
    int findNthDigit(int n) {
        if(n < 10) return n;
        vector<long long> t;
        long long b = 9;
        for(long long int i = 1; i <= 10; i++){
            t.push_back(b * i);
            b *= 10;
        }
        int idx = 0;
        while(n > t[idx]){
            n -= t[idx], idx++;
        }
        int ans = 1;
        for(int i = 0; i < idx; i++) ans *= 10; ans--;
        int x = (n + idx) / (idx + 1), y = (n + idx) % (idx + 1);
        cout << idx << ' ' << x << ' ' << y << ' ' << ans + x << endl;
        return to_string(ans + x)[y] - '0';
    }
};