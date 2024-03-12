// https://leetcode.com/problems/construct-the-rectangle

class Solution {
public:
    vector<int> constructRectangle(int area) {
        int x = floor(sqrt(area));
        for(int i = x; i >= 1; i--){
            if(area % i == 0) return {area / i, i};
        }
        return {area, 1};
    }
};