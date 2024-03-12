// https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int, int>tmp;
        for(int i: tasks)tmp[i]++;
        int ans = 0;
        for(auto &[k, v]: tmp){
            if(v < 2) return -1;
            else{
                ans += (v+2) / 3;
            }
        }
        return ans;
    }
};