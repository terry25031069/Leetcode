// https://leetcode.com/problems/find-all-people-with-secret

class Solution {
public:
    int find(int x, vector<int>& p){
        if(p[x] != x) p[x] = find(p[x], p);
        return p[x];
    }
    void merge(int x, int y, vector<int>& p){
        int fx = find(p[x], p);
        int fy = find(p[y], p);
        if(!fx ^ !fy){
            if(!fx) p[y] = 0;
            if(!fy) p[x] = 0;
        }
    }
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<int> p(n);
        for(int i = 0; i < n; i++) p[i] = i;
        meetings.push_back({0, firstPerson, 0});
        sort(meetings.begin(), meetings.end(), [](vector<int> a, vector<int>b){return a[2] < b[2];});
        for(auto v: meetings){
            merge(v[0], v[1], p);
        }
        vector<int> ans;
        for(int i = 0; i < n; i++){
            p[i] = find(p[i], p);
            if(!p[i]) ans.push_back(i);
        }
        return ans;
    }
};