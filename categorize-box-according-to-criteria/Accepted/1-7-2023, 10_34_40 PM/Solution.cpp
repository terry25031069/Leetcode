// https://leetcode.com/problems/categorize-box-according-to-criteria

class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        int a, b;
        a = b = 0;
        int64_t vol = int64_t(length) * int64_t(width) * int64_t(height);
        if(vol >= 1e9 || length >= 1e4 || width >= 1e4 || height >= 1e4){
            a = 1;
        }
        if(mass >= 100) b = 1;
        if(a && b) return "Both";
        if(a) return "Bulky";
        if(b) return "Heavy";
        return "Neither";
    }
};