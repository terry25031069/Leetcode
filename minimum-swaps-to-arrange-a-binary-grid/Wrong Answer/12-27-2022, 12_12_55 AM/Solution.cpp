// https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        vector<pair<vector<int>, int>> tmp;
        for(auto v: grid){
            int location = 0;
            for(int i = v.size() - 1; i > -1; i--){
                if(v[i]){
                    location = i; break;
                }
            }
            tmp.push_back({v, location});
        }
        int ans = 0;
        for(int i = tmp.size(); i > 0; i--){
            for(int j = 1; j < i; j++){
                if(tmp[j - 1].second > tmp[j].second){
                    swap(tmp[j - 1], tmp[j]);
                    ans++;
                }
            }
        }
        for(int i = 0; i < tmp.size(); i++){
            if(tmp[i].second > i + 1) return -1;
        }
        return ans;
    }
};