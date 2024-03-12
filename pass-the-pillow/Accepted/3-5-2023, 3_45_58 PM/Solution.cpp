// https://leetcode.com/problems/pass-the-pillow

class Solution {
public:
    int passThePillow(int n, int time) {
        n = n * 2 - 2;
        int tmp = time % n;
        if(tmp == 0) return 1;
        if(tmp == n/2) return n/2+1;
        if(tmp > n/2) return n - tmp + 1;
        if(tmp < n/2) return tmp + 1;
        return -1;
    }
};