// https://leetcode.com/problems/domino-and-tromino-tiling

class Solution {
public:
    int numTilings(int n) {
        int N = int(1e9+7);
        long long a[1001] = {1, 1, 2, 5, 11};
        for(int i = 4; i <= n; i++){
            a[i] = (2 * a[i-1] + a[i-3]) % N;
        }
        return a[n];
    }
};