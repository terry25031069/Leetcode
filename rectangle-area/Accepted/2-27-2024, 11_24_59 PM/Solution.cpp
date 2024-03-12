// https://leetcode.com/problems/rectangle-area

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int x, y;
        if (ax2 <= bx1 || ay1 >= by2 || ax1 >= bx2 || ay2<= by1) {
            x = y = 0;
        }else{
            x = min(ax2, bx2) - max(ax1, bx1);
            y = min(ay2, by2) - max(ay1, by1);
        }
        return (ay2 - ay1) * (ax2 - ax1) + (by2 - by1) * (bx2 - bx1) - x * y;
    }
};