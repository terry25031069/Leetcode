// https://leetcode.com/problems/count-operations-to-obtain-zero

class Solution {
public:
    int countOperations(int a, int b) {
        if(a == 0 || b == 0) return 0;
        int cnt = 0;
        if(a < b) swap(a, b);
        while(b){
            cnt += a / b;
            int t = a % b; a = b; b = t;
            if(a < b) swap(a, b);
        }
        return cnt;
    }
};