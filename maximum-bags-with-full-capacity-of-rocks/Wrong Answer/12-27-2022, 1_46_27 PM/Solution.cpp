// https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks

class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        for(int i = 0; i < capacity.size(); i++){
            capacity[i] -= rocks[i];
        }
        sort(capacity.begin(), capacity.end());
        int ans = 0;
        while(ans < capacity.size() && additionalRocks){
            additionalRocks -= capacity[ans];
            ans++;
        }
        return ans;
    }
};