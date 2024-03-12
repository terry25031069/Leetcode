// https://leetcode.com/problems/maximum-enemy-forts-that-can-be-captured

class Solution {
public:
    int captureForts(vector<int>& forts) {
        int ans = -1, cur, tot = 0, i;
        for(i = 0; i < forts.size() && i != 0; i++);
        cur = forts[i];
        cout << i << ' ' << cur << endl;
        for(; i < forts.size(); i++){
            if(cur + forts[i] == 0){
                ans = max(ans, tot);
                tot = 0, cur = forts[i];
            }else if(forts[i] == 0){
                tot++;
            }else{
                tot = 0;
            }
        }
        return ans;
    }
};