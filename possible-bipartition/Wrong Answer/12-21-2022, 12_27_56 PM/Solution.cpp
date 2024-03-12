// https://leetcode.com/problems/possible-bipartition

class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
       bool group[n + 1];
       memset(group, 0, sizeof(group));
       for(vector<int> v: dislikes){
           if(!group[v[0]] && !group[v[1]]) group[v[0]] = 1, group[v[1]] = 2;
           else if(!group[v[0]]) group[v[0]] = 3 - group[v[1]];
           else if(!group[v[1]]) group[v[1]] = 3 - group[v[0]];
           else{
               if(group[v[0]] == group[v[1]]) return false;
           }
       }
       return true;
    }
};