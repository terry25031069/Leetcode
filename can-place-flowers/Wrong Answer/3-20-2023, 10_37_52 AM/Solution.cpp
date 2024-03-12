// https://leetcode.com/problems/can-place-flowers

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(flowerbed.size() == 1 && !flowerbed[0]) return 1 >= n;
        int ans = 0, tmp = 0;
        vector<int> c;
        for(auto i: flowerbed){
            if(i){
                c.push_back(tmp);
                tmp = 0;
            }else tmp++;
        }
        if(tmp) c.push_back(tmp);
        else c.push_back(0);
        for(int i = 0; i < c.size(); i++){
            if(i == 0 || i == c.size() - 1){
                ans += c[i] / 2;
            }else ans += (c[i] > 2) * ((c[i] + 1) / 2 - 1);
        }
        return ans >= n;
    }
};