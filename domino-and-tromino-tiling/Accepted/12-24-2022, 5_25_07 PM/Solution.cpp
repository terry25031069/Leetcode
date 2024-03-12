// https://leetcode.com/problems/domino-and-tromino-tiling

class Solution {
public:
    int numTilings(int n) {
        long long a[1001] = {1, 1, 2, 5}, b[1001] = {1, 1, 1, 2};
        for(int i = 3; i < 1001; i++) b[i] = 2;    
        for(int i = 4; i < 1001; i++){
            for(int j = 1; j < i; j++){
                a[i] += b[j] * a[i-j];
            }
            a[i] = (a[i] + 2) % int(1e9+7);
        }
        return a[n];
    }
};