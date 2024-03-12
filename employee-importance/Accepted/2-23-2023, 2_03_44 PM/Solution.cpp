// https://leetcode.com/problems/employee-importance

/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    using piv = pair<int, vector<int>>;
    map<int, piv> m;
    int dfs(int id){
        int ans = m[id].first;
        for(auto s: m[id].second){
            ans += dfs(s);
        }
        return ans;
    }
    
    int getImportance(vector<Employee*> employees, int id) {
        for(auto i: employees){
            m[i->id] = {i->importance, i->subordinates};
        }
        return dfs(id);
    }
};