// https://leetcode.com/problems/can-place-flowers

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        flowerbed.push_back(1);
        int ans = 0, tmp = 0;
        for(auto i: flowerbed){
            if(i){
                if(tmp > 2) ans += tmp / 2;
                tmp = 0;
            }else{
                tmp++;
            }
        }
        return ans >= n;
    }
};