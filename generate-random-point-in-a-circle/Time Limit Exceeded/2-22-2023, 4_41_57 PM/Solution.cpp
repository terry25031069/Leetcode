// https://leetcode.com/problems/generate-random-point-in-a-circle

class Solution {
public:
    double rad, x_cen, y_cen;
    double fRand(double fMin, double fMax){
        double f = (double)rand() / RAND_MAX;
        return fMin + f * (fMax - fMin);
    }

    Solution(double radius, double x_center, double y_center) {
        rad = radius, x_cen = x_center, y_cen = y_center;
    }
    
    vector<double> randPoint() {
        double dx, dy;
        do{
            dx = fRand(-rad, rad), dy = fRand(-rad, rad);
        }while(dx*dx + dy*dy >= rad);
        return {x_cen + dx, y_cen + dy};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */