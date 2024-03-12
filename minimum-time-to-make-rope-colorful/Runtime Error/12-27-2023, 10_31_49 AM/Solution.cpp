// https://leetcode.com/problems/minimum-time-to-make-rope-colorful

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        colors += 'R';
        int ans = 0, n = colors.size();
        int cn = 1, tot = neededTime[0], ma = neededTime[0];
        char cc = colors[0];
        for(int i = 1; i < n; i++){
            if(colors[i] == cc){
                cn++, tot += neededTime[i], ma = max(neededTime[i], ma);
            }else{
                if(cn > 1){
                    cout << tot << ' ' << ma << endl;
                    ans += tot - ma;    
                }
                cc = colors[i];
                tot = ma = neededTime[i];
                cn = 1;
            }
        }
        return ans;
    }
};