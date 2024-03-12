// https://leetcode.com/problems/watering-plants

class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int ans = 1, tmp = capacity;
        for(int i = 0; i < plants.size(); i++){
            if(tmp < plants[i]) ans += i * 2, tmp = capacity;
            tmp -= plants[i], ans += (i < plants.size() - 1);
            //cout << ans << endl;
        }
        return ans;
    }
};