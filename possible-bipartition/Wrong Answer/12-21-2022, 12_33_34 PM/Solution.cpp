// https://leetcode.com/problems/possible-bipartition

class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b){
        if(a[0] != b[0]) return a[0] < b[0];
        return a[1] < b[1];
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
       bool group[n + 1];
       memset(group, 0, sizeof(group));
       sort(dislikes.begin(), dislikes.end(), cmp);
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