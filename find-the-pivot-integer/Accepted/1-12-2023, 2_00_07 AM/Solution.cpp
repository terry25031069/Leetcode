// https://leetcode.com/problems/find-the-pivot-integer

class Solution {
public:
    int pivotInteger(int n) {
        if(n == 1) return 1;
        if(int(sqrt((n*n+n)/2)) == sqrt((n*n+n)/2)) return sqrt((n*n+n)/2);
        return -1;
    }
};